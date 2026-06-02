#include <stdio.h>

int main() {
    int n, frames, i, j, k;

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

    int fault = 0;

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

            int pos = -1, farthest = -1;

            for(j = 0; j < frames; j++) {

                int nextUse = n;

                for(k = i + 1; k < n; k++) {
                    if(frame[j] == pages[k]) {
                        nextUse = k;
                        break;
                    }
                }

                if(nextUse > farthest) {
                    farthest = nextUse;
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            fault++;
        }

        printf("%d\t", pages[i]);

        for(j = 0; j < frames; j++) {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }

        printf(found ? "\tHit\n" : "\tFault\n");
    }

    printf("\nTotal Page Faults = %d\n", fault);

    return 0;
}
