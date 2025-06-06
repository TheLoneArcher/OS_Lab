#include <stdio.h>
void bestFit(int partitions[], int m, int processes[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1; // initialize allocation array to be -1 for all
    for (int i = 0; i < n; i++) {
        int minIndex = -1; // find minimum index
        for (int j = 0; j < m; j++) if (partitions[j] >= processes[i] && (minIndex == -1 || partitions[j] < partitions[minIndex])) minIndex = j; // if partitions are great enough to hold the process and minimum is not there or if partition is less than min index, update min index
        if (minIndex != -1) {
            allocation[i] = minIndex;
            partitions[minIndex] -= processes[i]; // subtract the process memory needed from the partition as the partition has allocated space to the process
        }
    }
    for (int i = 0; i < n; i++) {
        printf("Process %d ", i + 1);
        if (allocation[i] != -1) printf("Allocated to Partition %d\n", allocation[i] + 1);
        else printf("Not allocated\n");
    }
}
int main() {
    int partitions[] = {100, 500, 200, 300, 600}, processes[] = {212, 417, 112, 426}, m = sizeof(partitions) / sizeof(partitions[0]), n = sizeof(processes) / sizeof(processes[0]);
    bestFit(partitions, m, processes, n);
    return 0;
}
