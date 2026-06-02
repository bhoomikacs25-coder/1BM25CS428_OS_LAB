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

    int frame[frames], time[frames];

    for(i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    int count = 0, fault = 0;

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                count++;
                time[j] = count;
                break;
            }
        }

        if(!found) {
            int pos = 0;

            for(j = 1; j < frames; j++) {
                if(time[j] < time[pos])
                    pos = j;
            }

            frame[pos] = pages[i];
            count++;
            time[pos] = count;
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
