#include <stdio.h>

int main()
{
    int m, n, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    int block[m];

    printf("Enter sizes of %d memory blocks:\n", m);
    for(i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int process[n];

    printf("Enter sizes of %d processes:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &process[i]);

    /* First Fit */
    int b1[m];
    for(i = 0; i < m; i++)
        b1[i] = block[i];

    printf("\n--- First Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < n; i++)
    {
        int alloc = -1;

        for(j = 0; j < m; j++)
        {
            if(b1[j] >= process[i])
            {
                alloc = j;
                b1[j] -= process[i];
                break;
            }
        }

        printf("%d\t\t%d\t\t", i + 1, process[i]);

        if(alloc != -1)
            printf("%d\n", alloc + 1);
        else
            printf("Not Allocated\n");
    }

    /* Best Fit */
    int b2[m];
    for(i = 0; i < m; i++)
        b2[i] = block[i];

    printf("\n--- Best Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < n; i++)
    {
        int best = -1;

        for(j = 0; j < m; j++)
        {
            if(b2[j] >= process[i])
            {
                if(best == -1 || b2[j] < b2[best])
                    best = j;
            }
        }

        printf("%d\t\t%d\t\t", i + 1, process[i]);

        if(best != -1)
        {
            printf("%d\n", best + 1);
            b2[best] -= process[i];
        }
        else
            printf("Not Allocated\n");
    }

    /* Worst Fit */
    int b3[m];
    for(i = 0; i < m; i++)
        b3[i] = block[i];

    printf("\n--- Worst Fit ---\n");
    printf("Process No.\tProcess Size\tBlock No.\n");

    for(i = 0; i < n; i++)
    {
        int worst = -1;

        for(j = 0; j < m; j++)
        {
            if(b3[j] >= process[i])
            {
                if(worst == -1 || b3[j] > b3[worst])
                    worst = j;
            }
        }

        printf("%d\t\t%d\t\t", i + 1, process[i]);

        if(worst != -1)
        {
            printf("%d\n", worst + 1);
            b3[worst] -= process[i];
        }
        else
            printf("Not Allocated\n");
    }

    return 0;
}
