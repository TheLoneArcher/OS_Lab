#include <stdio.h>
#include <stdbool.h>
int allocation[50][50], maximumDemand[50][50], availableResources[50], neededResources[50][50], safeSequence[50];
bool finishStatus[50]; // declare max, allocated, available, need, safe sequence, and finish arrays
bool canBeSatisfied(int processIndex, int numResources, int work[]) {
    for (int i = 0; i < numResources; i++) if (neededResources[processIndex][i] > work[i]) return false;
    return true;
}
int main() {
    int numProcesses, numResources, safeCount = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);
    printf("Enter the number of resources: ");
    scanf("%d", &numResources);
    // enter the allocation, and maximum matrices and available array
    printf("Enter resource allocation matrix: \n");
    for (int i = 0; i < numProcesses; i++) {
        finishStatus[i] = false; // initialize finish status to false
        for (int j = 0; j < numResources; j++) scanf("%d", &allocation[i][j]);
    }
    printf("Enter maximum resources matrix: \n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            scanf("%d", &maximumDemand[i][j]);
            neededResources[i][j] = maximumDemand[i][j] - allocation[i][j];
        }
    }
    printf("Enter available resources: \n");
    int workResources[numResources];
    for (int i = 0; i < numResources; i++) {
        scanf("%d", &availableResources[i]);
        workResources[i] = availableResources[i];
    }
    // print the needed resources matrix
    printf("Needed resources are: \n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            printf("%d ", neededResources[i][j]);
        }
        printf("\n");
    }
    // the main logic of the Banker's algorithm
    while (safeCount < numProcesses) { // while the safe count is less than the number of processes
        // find a process that can be satisfied
        bool found = false;
        for (int i = 0; i < numProcesses; i++) { // iterate throug the processes 
            if (!finishStatus[i] && canBeSatisfied(i, numResources, workResources)) { // check if the process is not finished and that it can be satisfied
                safeSequence[safeCount++] = i;
                finishStatus[i] = true;
                for (int j = 0; j < numResources; j++) workResources[j] += allocation[i][j];
                found = true;
                // if it can be satisfied and it isn't finished then set its safe sequence to the urrent node and then set the finish status to true and reclaim the resources then set found to true
            }
        }
        if (!found) break; // if any process can't be satisfied then break the loop
    }
    if (safeCount == numProcesses) { // if the safe count is equal to the number of processes then print the safe sequence or else say that deadlock occured
        printf("The safe sequence is:");
        for (int i = 0; i < numProcesses; i++) printf(" p%d ", safeSequence[i] + 1);
        printf("\n");
    } else {
        printf("Deadlock occurred\n");
    }
    return 0;
}