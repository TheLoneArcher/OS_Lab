#include <stdio.h>
void main() {
    int turnaroundTime[10], burstTime[10], waitingTime[10], i; // P BT WT TAT
    float averageWaitingTime = 0, averageTurnaroundTime = 0, numberOfProcesses;
    printf("Enter the number of processes:");
    scanf("%f", &numberOfProcesses);
    for (i = 1; i <= numberOfProcesses; i++) {
        printf("P%d\tBurst Time: ", i);
        scanf("%d", &burstTime[i]); // only take burst time bcz all the arrival times are taken as 0
    }
    printf("\nP\tBT\tWT\tTAT\n"); // print the table
    for (i = 1; i <= numberOfProcesses; i++) {
        turnaroundTime[i] = burstTime[i] + waitingTime[i]; // turnaround time is the time taken to finish the task including waiting
        averageTurnaroundTime += turnaroundTime[i];
        waitingTime[i] = (i == 1) ? 0 : turnaroundTime[i - 1]; // the process waits until the previous process is complete
        averageWaitingTime += waitingTime[i];
        printf("P%d\t%d\t%d\t%d\n", i, burstTime[i], waitingTime[i], turnaroundTime[i]);
    }
    printf("Average waiting time: %.2f\n", averageWaitingTime / numberOfProcesses);
    printf("Average turn around time: %.2f\n", averageTurnaroundTime / numberOfProcesses);
}