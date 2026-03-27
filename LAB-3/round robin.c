#include <stdio.h>

void round_robin(int n,int AT[],int BT[],int tq){

    int CT[n],TAT[n],WT[n],RT[n];
    int temp_BT[n],completed[n],first_time[n];
    for(int i=0;i<n;i++){
        temp_BT[i]=BT[i];
        completed[i]=0;
        first_time[i]=-1;
    }
    int t=0,count=0;
    while(count<n){
        int executed=0;
        for(int i=0;i<n;i++){
            if(AT[i]<=t && completed[i]==0){
                if(first_time[i]==-1)
                    first_time[i]=t;
                if(temp_BT[i]>tq){
                    temp_BT[i]-=tq;
                    t+=tq;
                }
                else{
                    t+=temp_BT[i];
                    temp_BT[i]=0;
                    CT[i]=t;
                    TAT[i]=CT[i]-AT[i];
                    WT[i]=TAT[i]-BT[i];
                    RT[i]=first_time[i]-AT[i];
                    completed[i]=1;
                    count++;
                }
                executed=1;
            }
        }
        if(executed==0)
            t++;
    }
    float avgTAT=0,avgWT=0,avgRT=0;
    printf("\nRound Robin Result:\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,AT[i],BT[i],CT[i],TAT[i],WT[i],RT[i]);
        avgTAT+=TAT[i];
        avgWT+=WT[i];
        avgRT+=RT[i];
    }
    printf("\nAverage TAT = %.2f",avgTAT/n);
    printf("\nAverage WT  = %.2f",avgWT/n);
}

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    int AT[n],BT[n];
    for(int i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d%d",&AT[i],&BT[i]);
    }
    int tq;
    printf("Enter Time Quantum: ");
    scanf("%d",&tq);
    round_robin(n,AT,BT,tq);
    return 0;
}
