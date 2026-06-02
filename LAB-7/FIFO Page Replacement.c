#include <stdio.h>

int main() {
    int n, frames, i, j;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[frames];
    for(i = 0; i < frames; i++)
        frame[i] = -1;

    int fault = 0, ptr = 0;

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frame[ptr] = pages[i];
            ptr = (ptr + 1) % frames;
            fault++;
        }

        printf("%d\t", pages[i]);

        for(j = 0; j < frames; j++) {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }

        if(found)
            printf("\tHit");
        else
            printf("\tFault");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", fault);

    return 0;
}
