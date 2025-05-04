#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int page, freq;
} Page;

int find_page(Page *p, int n, int page) {
    for (int i = 0; i < n; i++)
        if (p[i].page == page)
            return i;
    return -1;
}

void swap(Page *p, int i, int j) {
    Page t = p[i];
    p[i] = p[j];
    p[j] = t;
}

void print_frames(Page *p, int n) {
    for (int i = 0; i < n; i++)
        printf("\t%d", p[i].page == -1 ? -1 : p[i].page);
}

int main() {
    int n, c, *pages, pf = 0, pc = 0;
    
    printf("Enter length of reference string: ");
    scanf("%d", &n);
    
    pages = malloc(n * sizeof(int));
    printf("Enter reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    
    printf("Enter number of frames: ");
    scanf("%d", &c);
    
    Page *v = malloc(c * sizeof(Page));
    for (int i = 0; i < c; i++)
        v[i].page = -1, v[i].freq = 0;
    
    printf("Page Replacement Process (LFU):\n");
    
    for (int i = 0; i < n; i++) {
        int pos = find_page(v, pc, pages[i]);
        
        if (pos == -1) {
            if (pc == c) {
                v[0].freq--;
                for (int j = 0; j < c - 1; j++)
                    v[j] = v[j + 1];
                pc--;
            }
            v[pc].page = pages[i];
            v[pc].freq = 1;
            pc++;
            pf++;
            print_frames(v, c);
            printf("\tPF No. %d\n", pf);
        } else {
            v[pos].freq++;
            for (int j = pos; j < pc - 1; j++)
                v[j] = v[j + 1];
            v[pc - 1].page = pages[i];
            v[pc - 1].freq++;
            for (int k = pc - 2; k >= 0; k--)
                if (v[k].freq > v[k + 1].freq)
                    swap(v, k, k + 1);
                else
                    break;
            print_frames(v, c);
            printf("\n");
        }
    }
    
    printf("Number of Page Faults (LFU): %d\n", pf);
    
    free(pages);
    free(v);
    return 0;
}