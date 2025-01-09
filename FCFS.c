#include<stdio.h>
int main(){
    int at[10],bt[10],wt[10],ft[10],tat[10],i,j,n,temp1,temp2,x=0;
    int twt=0,ttat=0;
    fflush(stdin);
    printf("Enter number of processes:\n");
    scanf("%d",&n);
    printf("Enter arrived times:\n");
    for(i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    printf("Enter burst times:\n");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    printf("Sorting arrived times and burst times\n");
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(at[i]>at[j]){
                temp1=at[i];
                at[i]=at[j];
                at[j]=temp1;
                temp2=bt[i];
                bt[i]=bt[j];
                bt[j]=temp2;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d\n\t%d\n",at[i],bt[i]);
    }
    printf("Calculation of finishing time,waiting time,turn around time\n");
    for(i=0;i<n;i++){
        x=x+bt[i];
        ft[i]=x;
        wt[i]=ft[i]-(at[i]+bt[i]);
        tat[i]=ft[i]-at[i];
        printf("%5d\t %5d\t %5d\t",ft[i],wt[i],tat[i]);
    }
    for(i=0;i<n;i++){
        twt=twt+wt[i];
        ttat=ttat+tat[i];
    }
    float awt1=(float)twt/n;
    float atat1=(float)ttat/n;
    printf("Average turn around time is: %f\nAverage waiting time is: %f\n",awt1,atat1);
}
