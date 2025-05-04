#include <stdio.h>

void main() {
    int memorySize, pageSize, numberOfPages, numberOfProcesses, remainingPages, i, j, processNumber, pageNumber, addressOffset, physicalAddress;
    int processSize[10], frameNumberTable[10][20];

    printf("Enter the memory size: ");
    scanf("%d", &memorySize);

    printf("Enter the page size: ");
    scanf("%d", &pageSize);

    numberOfPages = memorySize / pageSize;
    printf("The number of pages available in memory are: %d \n", numberOfPages);

    printf("Enter the number of processes: ");
    scanf("%d", &numberOfProcesses);

    remainingPages = numberOfPages;
    for (i = 1; i <= numberOfProcesses; i++) {
        printf("Enter the number of pages required for process [%d]: ", i);
        scanf("%d", &processSize[i]);

        if (processSize[i] > remainingPages) {
            printf("Memory is Full\n");
            break;
        }

        remainingPages -= processSize[i];
        printf("Enter page table for process [%d]: ", i);
        for (j = 0; j < processSize[i]; j++)
            scanf("%d", &frameNumberTable[i][j]);
    }

    printf("Enter Logical Address to find Physical Address\n");
    printf("Enter process number, page number, and offset: ");
    scanf("%d %d %d", &processNumber, &pageNumber, &addressOffset);

    if (processNumber > numberOfProcesses || pageNumber >= processSize[processNumber] || addressOffset >= pageSize)
        printf("Invalid Process or Page Number or offset\n");
    else {
        physicalAddress = frameNumberTable[processNumber][pageNumber] * pageSize + addressOffset;
        printf("The Physical Address is: %d\n", physicalAddress);
    }
}