#include <stdio.h>
void main() {
    int memorySize, pageSize, numberOfPages, numberOfProcesses, remainingPages, i, j, processNumber, pageNumber, addressOffset, physicalAddress, processSize[10], frameNumberTable[10][20];
    printf("Enter the memory size: ");
    scanf("%d", &memorySize);
    printf("Enter the page size: ");
    scanf("%d", &pageSize); // ask for the total memory size and the page size to calculate the number of pages
    numberOfPages = memorySize / pageSize;
    remainingPages = numberOfPages;
    printf("The number of pages available in memory are: %d \n", numberOfPages);
    printf("Enter the number of processes: ");
    scanf("%d", &numberOfProcesses); // ask for the number of processes
    for (i = 1; i <= numberOfProcesses; i++) { // iterate for each process
        printf("Enter the number of pages required for process [%d]: ", i); // ask for the number of pages requierd for the process
        scanf("%d", &processSize[i]);
        if (processSize[i] > remainingPages) { // if the memory pages are not enough then break
            printf("Memory is Full\n");
            break;
        }
        remainingPages -= processSize[i]; // allocate frames to the process pages
        printf("Enter page table for process [%d]: ", i);
        for (j = 0; j < processSize[i]; j++)
            scanf("%d", &frameNumberTable[i][j]); // ask the user for the page table
    }
    printf("Enter Logical Address to find Physical Address\n");
    printf("Enter process number, page number, and offset: ");
    scanf("%d %d %d", &processNumber, &pageNumber, &addressOffset); // ask the user for the process number for which logical address is needed, the page number and the offset
    if (processNumber > numberOfProcesses || pageNumber >= processSize[processNumber] || addressOffset >= pageSize)
        printf("Invalid Process or Page Number or offset\n");
    else {
        physicalAddress = frameNumberTable[processNumber][pageNumber] * pageSize + addressOffset; // deconstruct the frame and add the offset
        printf("The Physical Address is: %d\n", physicalAddress); 
    }
}
