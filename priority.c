#include<stdio.h>
#define max 20
int main()
{
    int bt[max],at[max],p[max],wt[max],tat[max],ft[max];
    int i,j,n,x=0,y=0,z=0,min=0,temp1,temp2,temp3,k,l;
    float t,u;
    printf("Enter the number of processes to be executed \n:");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        printf("enter the burst time for process-%d\n",i);
        scanf("%d",&bt[i]);
         printf("enter the arrival time for process-%d\n",i);
        scanf("%d",&at[i]);
        printf("enter the priority time for process-%d\n",i);
        scanf("%d",&p[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(at[i]>at[j])
            {
                temp1=at[i];
                at[i]=at[j];
                at[j]=temp1;

                temp2=bt[i];
                bt[i]=bt[j];
                bt[j]=temp2;

                temp3=p[i];
                p[i]=p[j];
                p[j]=temp3;
            }
            else if(at[i]==at[j] && p[i]>p[j])
            {
                temp1=at[i];
                at[i]=at[j];
                at[j]=temp1;

                temp2=bt[i];
                bt[i]=bt[j];
                bt[j]=temp2;

                temp3=p[i];
                p[i]=p[j];
                p[j]=temp3;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        min+=bt[i];
        for(j=i+1;at[j]<min;j++)
        {
            for(k=j+1;at[k]<=min;k++)
            {
                if(p[k]<p[j])
                {
                    temp1=at[k];
                    at[k]=at[j];
                    at[j]=temp1;

                    temp2=bt[k];
                    bt[k]=bt[j];
                    bt[j]=temp2;

                    temp3=p[i];
                    p[i]=p[j];
                    p[j]=temp3;
                }
            }
        }
    }
    for(i=0;i<n;i++)
    {
        x+=bt[i];
        ft[i]=x;
        if(i==1)
            wt[i]=y;
        else
            wt[i]=ft[i-1]-at[i];
        tat[i]=bt[i]+wt[i];
    }
    for(i=1;i<=n;i++)
    {
        y+=tat[i];
        z+=wt[i];
    }
    for(i=1;i<=n;i++)
    {
        printf("\nProcess : %d-->at:%d\tbt:%d\tft:%d\twt:%d\tat:%d\t",i,at[i],bt[i],ft[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time:%d",z/n);
    printf("\nAverage Turn Around T
