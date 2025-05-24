#include <stdio.h>
void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }
int main() {
    int turnaroundTime[10], burstTime[10], waitingTime[10], priority[10], processId[10], i, j, n; // P BT PRI WT TAT
    float averageWaitingTime = 0, averageTurnaroundTime = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("P%d\tBurst Time: ", i + 1);
        scanf("%d", &burstTime[i]);
        printf("\tPriority: ");
        scanf("%d", &priority[i]);
        processId[i] = i + 1;
    }
    printf("Process Schedule: ");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (priority[i] > priority[j] || (priority[i] == priority[j] && processId[i] > processId[j])) {
                swap(&priority[i], &priority[j]); swap(&burstTime[i], &burstTime[j]); swap(&processId[i], &processId[j]);
            }
        }
        printf("%d\t", processId[i]);
    }
    printf("\nP\tBT\tPRI\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
        averageTurnaroundTime += turnaroundTime[i];
        waitingTime[i] = (i == 0) ? 0 : turnaroundTime[i - 1];
        averageWaitingTime += waitingTime[i];
        printf("P%d\t%d\t%d\t%d\t%d\n", processId[i], burstTime[i], priority[i], waitingTime[i], turnaroundTime[i]);
    }
    printf("Average waiting time: %.2f\n", averageWaitingTime / n);
    printf("Average turn around time: %.2f\n", averageTurnaroundTime / n);
    return 0;
}