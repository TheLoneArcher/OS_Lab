#include <stdio.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void main() {
    int turnaroundTime[10], burstTime[10], waitingTime[10], processId[10], i, j, k, numberOfProcesses; // P AT BT TAT WT 
    float averageWaitingTime = 0, averageTurnaroundTime = 0;
    printf("Enter the number of processes:");
    scanf("%d", &numberOfProcesses);
    for (i = 1; i <= numberOfProcesses; i++) {
        printf("P%d\tBurst Time: ", i);
        scanf("%d", &burstTime[i]);
        processId[i] = i;
    }
    printf("Process Schedule: ");
    for (i = 1; i <= numberOfProcesses; i++) {
        for (j = i + 1; j <= numberOfProcesses; j++) {
            if (burstTime[i] > burstTime[j] || (burstTime[i] == burstTime[j] && processId[i] > processId[j])) {
                swap (&burstTime[i], &burstTime[j]);
                swap(&processId[i], &processId[j]);
            }
        }
        printf("p%d\t", processId[i]); // bubbled element
    }
    printf("\nP\tBT\tTAT\tWT\n");
    for (i = 1; i <= numberOfProcesses; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
        averageTurnaroundTime += turnaroundTime[i];
        waitingTime[i] = (i == 1) ? 0 : turnaroundTime[i - 1];
        averageWaitingTime += waitingTime[i];
        printf("P%d\t%d\t%d\t%d\n", processId[i], burstTime[i], turnaroundTime[i], waitingTime[i]);
    }
    printf("Average waiting time:%.2f\n", averageWaitingTime / numberOfProcesses);
    printf("Average turn around time:%.2f\n", averageTurnaroundTime / numberOfProcesses);
}