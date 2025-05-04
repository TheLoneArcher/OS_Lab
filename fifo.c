#include <stdio.h>
#include <stdbool.h>
int main() {
    int refLen, frameCount, faults = 0, frameIndex = 0;
    int refStr[25], frames[10], currentPage;
    printf("Enter length of reference string: ");
    scanf("%d", &refLen);
    printf("Enter reference string: ");
    for (int i = 0; i < refLen; i++) scanf("%d", &refStr[i]);
    printf("Enter number of frames: ");
    scanf("%d", &frameCount);
    for (int i = 0; i < frameCount; i++) frames[i] = -1;
    printf("Page Replacement Process (FIFO):\n");
    for (int i = 0; i < refLen; i++) {
        currentPage = refStr[i];
        bool found = false;
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == currentPage) {
                found = true;
                break;
            }
        }
        if (!found) {
            frames[frameIndex++] = currentPage;
            faults++;
            if (frameIndex == frameCount) frameIndex = 0;
        }
        for (int j = 0; j < frameCount; j++) printf("\t%d", frames[j]);
        if (!found) printf("\tPF No. %d", faults);
        printf("\n");
    }
    printf("Number of Page Faults (FIFO): %d\n", faults);
    return 0;
}