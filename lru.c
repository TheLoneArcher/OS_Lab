#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_page(int *pages, int n, int page) {
    for (int i = 0; i < n; i++)
        if (pages[i] == page)
            return i;
    return -1;
}

void print_frames(int *frames, int n) {
    for (int i = 0; i < n; i++)
        if (frames[i] == -1)
            printf("\t-1");
        else
            printf("\t%d", frames[i]);
}

int main() {
    int n, frames, *ref_str, *pages, page_faults = 0, page_count = 0;

    printf("Enter length of reference string: ");
    scanf("%d", &n);
    
    ref_str = (int *)malloc(n * sizeof(int));
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &ref_str[i]);
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    pages = (int *)malloc(frames * sizeof(int));
    memset(pages, -1, frames * sizeof(int));
    
    printf("Page Replacement Process (LRU):\n");
    
    for (int i = 0; i < n; i++) {
        int pos = find_page(pages, frames, ref_str[i]);
        
        if (pos == -1) {
            if (page_count < frames) {
                pages[page_count++] = ref_str[i];
            } else {
                for (int j = 0; j < frames - 1; j++)
                    pages[j] = pages[j + 1];
                pages[frames - 1] = ref_str[i];
            }
            page_faults++;
            print_frames(pages, frames);
            printf("\tPF No. %d\n", page_faults);
        } else {
            for (int j = pos; j < frames - 1; j++)
                pages[j] = pages[j + 1];
            pages[frames - 1] = ref_str[i];
            print_frames(pages, frames);
            printf("\n");
        }
    }
    
    printf("Number of Page Faults (LRU): %d\n", page_faults);
    
    free(ref_str);
    free(pages);
    return 0;
}