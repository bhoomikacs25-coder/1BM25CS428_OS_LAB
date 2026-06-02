#include <stdio.h>

int main()
{
    int n,m,i,j,k;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resource types: ");
    scanf("%d",&m);

    int alloc[n][m], req[n][m], avail[m];
    int finish[n], work[m];

    printf("Enter Allocation Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&req[i][j]);

    printf("Enter Available Resources:\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
        work[i]=avail[i];
    }

    for(i=0;i<n;i++)
        finish[i]=0;

    int flag=1;

    while(flag)
    {
        flag=0;

        for(i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                for(j=0;j<m;j++)
                {
                    if(req[i][j] > work[j])
                        break;
                }

                if(j==m)
                {
                    for(k=0;k<m;k++)
                        work[k]+=alloc[i][k];

                    finish[i]=1;
                    flag=1;
                }
            }
        }
    }

    printf("\n");

    flag=0;
    for(i=0;i<n;i++)
    {
        if(finish[i]==0)
        {
            flag=1;
            break;
        }
    }

    if(flag)
    {
        printf("System is in Deadlock\n");
        printf("Deadlocked Processes: ");

        for(i=0;i<n;i++)
            if(finish[i]==0)
                printf("P%d ",i);
    }
    else
    {
        printf("No Deadlock Detected\n");
    }

    return 0;
}
