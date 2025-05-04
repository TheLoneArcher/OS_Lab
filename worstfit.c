#include <stdio.h>
void worstFit(int partitions[], int m, int processes[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        int maxIndex = -1;
        for (int j = 0; j < m; j++) if (partitions[j] >= processes[i] && (maxIndex == -1 || partitions[j] > partitions[maxIndex])) maxIndex = j;
        if (maxIndex != -1) {
            allocation[i] = maxIndex;
            partitions[maxIndex] -= processes[i];
        }
    }
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        if (allocation[i] != -1) printf("Allocated to Partition %d\n", allocation[i] + 1);
        else printf("Not allocated\n");
    }
}
int main() {
    int partitions[] = {100, 500, 200, 300, 600}, processes[] = {212, 417, 112, 426}, m = sizeof(partitions) / sizeof(partitions[0]), n = sizeof(processes) / sizeof(processes[0]);
    worstFit(partitions, m, processes, n);
    return 0;
}