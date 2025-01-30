#include<stdio.h>
main()
{
    int st[10],at[10],bt[10],wt[10],tat[10],n,tq;
    int i,count=0,swt=0,stat=0,temp,sq=0,j,temp1,temp2;
    float awt=0.0,atat=0.0;
    printf("\n enter num of processes to be executed: ");
    scanf("%d",&n);
    printf("\n enter burst time sequences: ");
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
    }
    printf("\n enter arrival times:\n");
    for(i=0;i<n;i++){
        scanf("%d",&at[i]);
    }
    printf("after sorting arrival times and burst times\n");
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
        st[i]=bt[i];
        printf("%d\t%d\t\n",at[i],bt[i]);
    }
    printf("\n enter time quamtum: ");
    scanf("%d",&tq);
    while(1)
    {

        for(i=0,count=0;i<n;i++){
            temp=tq;
            if(st[i]==0){
                count++;
                continue;
            }
            if(st[i]>tq)
                st[i]=st[i]-tq;
            else if(st[i]>=0){
                temp=st[i];
                st[i]=0;
            }
            sq=sq+temp;
            tat[i]=sq-at[i];
        }
        if(n==count)
            break;
    }
    for(i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        swt=swt+wt[i];
        stat=stat+tat[i];
    }
    awt=(float)swt/n;
    atat=(float)stat/n;
    printf("pno\t\t at \t\t bt \t\t wt \t\t tat\n");
    for(i=0;i<n;i++){
        printf("%d\t\t %d \t\t %d \t\t %d \t\t %d\n",i+1,at[i],bt[i],wt[i],tat[i]);
    }
    printf("\n average wt is:%f\naverage tat is :%f\n",awt,atat);
return 0;
}
