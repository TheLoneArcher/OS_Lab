#include <stdio.h>

int main() {
    int burstTime[10], remainingTime[10], waitingTime[10], turnaroundTime[10];
    int n, remainingProcesses, currentTime = 0, quantum;
    float avgWaitTime = 0, avgTurnaroundTime = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    remainingProcesses = n;
    for (int i = 0; i < n; i++) {
        printf("Enter burst time of p%d: ", i + 1);
        scanf("%d", &burstTime[i]);
        remainingTime[i] = burstTime[i];
    }
    printf("Enter quantum time: ");
    scanf("%d", &quantum);
    int i = 0;
    while (remainingProcesses > 0) {
        if (remainingTime[i] > 0) { // execute once
            int executedTime = (remainingTime[i] > quantum) ? quantum : remainingTime[i];
            currentTime += executedTime;
            remainingTime[i] -= executedTime;
            if (remainingTime[i] == 0) { // calculate wt and tat
                waitingTime[i] = currentTime - burstTime[i];
                turnaroundTime[i] = currentTime;
                remainingProcesses--;
            }
        }
        i = (i + 1) % n; // Cycle through processes
    }
    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (int j = 0; j < n; j++) {
        printf("p%d\t%d\t\t%d\n", j + 1, waitingTime[j], turnaroundTime[j]);
        avgWaitTime += waitingTime[j];
        avgTurnaroundTime += turnaroundTime[j];
    }

    printf("Average waiting time: %.2f\n", avgWaitTime / n);
    printf("Average turnaround time: %.2f\n", avgTurnaroundTime / n);

    return 0; 
}