#include <stdio.h>

void main() {
    int turnaroundTime[10], burstTime[10], waitingTime[10], i;
    float averageWaitingTime = 0, averageTurnaroundTime = 0, numberOfProcesses;
    printf("Enter the number of processes:");
    scanf("%f", &numberOfProcesses);
    for (i = 1; i <= numberOfProcesses; i++) {
        printf("P%d\tBurst Time: ", i);
        scanf("%d", &burstTime[i]);
    }
    printf("\nP\tBT\tWT\tTAT\n");
    for (i = 1; i <= numberOfProcesses; i++) {
        waitingTime[i] = (i == 1) ? 0 : waitingTime[i - 1] + burstTime[i - 1];
        averageWaitingTime += waitingTime[i];
        turnaroundTime[i] = burstTime[i] + waitingTime[i];
        averageTurnaroundTime += turnaroundTime[i];
        printf("P%d\t%d\t%d\t%d\n", i, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }
    printf("Average waiting time: %.2f\n", averageWaitingTime / numberOfProcesses);
    printf("Average turn around time: %.2f\n", averageTurnaroundTime / numberOfProcesses);
}