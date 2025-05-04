#include <stdio.h>
#include <stdbool.h>
int allocation[50][50], maximumDemand[50][50], availableResources[50], neededResources[50][50];
bool finishStatus[50];
int safeSequence[50];
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
    printf("Enter resource allocation matrix: \n");
    for (int i = 0; i < numProcesses; i++) {
        finishStatus[i] = false;
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
    printf("Needed resources are: \n");
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            printf("%d ", neededResources[i][j]);
        }
        printf("\n");
    }
    while (safeCount < numProcesses) {
        bool found = false;
        for (int i = 0; i < numProcesses; i++) {
            if (!finishStatus[i] && canBeSatisfied(i, numResources, workResources)) {
                safeSequence[safeCount++] = i;
                finishStatus[i] = true;
                for (int j = 0; j < numResources; j++) workResources[j] += allocation[i][j];
                found = true;
            }
        }
        if (!found) break; 
    }

    if (safeCount == numProcesses) {
        printf("The safe sequence is:");
        for (int i = 0; i < numProcesses; i++) printf(" p%d ", safeSequence[i] + 1);
        printf("\n");
    } else {
        printf("Deadlock occurred\n");
    }
    return 0;
}