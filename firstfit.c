#include <stdio.h>

void firstFit(int partitions[], int m, int processes[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
        for (int j = 0; j < m; j++) {
            if (partitions[j] >= processes[i]) {
                allocation[i] = j;
                partitions[j] -= processes[i];
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("Process %d %s Partition %d\n", i + 1,
               allocation[i] != -1 ? "allocated to" : "not allocated",
               allocation[i] + 1);
}

int main() {
    int partitions[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    firstFit(partitions, 5, processes, 4);
    return 0;
}

