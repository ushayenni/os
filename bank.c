#include<stdio.h>
int main()
{
    int available[3],work[5],max[5][3],allocation[5][3],need[5][3],safe[5],total_res[5];
    char finish[3];
    int i,j,k,totalloc=0,state,value=0;
    printf("\n Enter instances of each resources:");
    for(i=0;i<3;i++)
    {
        scanf("%d",&total_res[i]);
    }
    printf("\n Enter maximum no of resources for each process:");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\nEnter process %d resouces %d:",i,(j+1));
            scanf("%d",&max[i][j]);
        }
    }
    printf("\n Enter no of resources allocated to each process:");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\n Enter the resource of R %d allocated to process %d:",(j+1),i);
            scanf("%d",&allocation[i][j]);
        }
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            need[i][j]=max[i][j]-allocation [i][j];
        }
    }
    for(i=0;i<5;i++)
    {
        finish[i]='f';
    }
    for(i=0;i<3;i++)
    {
        totalloc=0;
        for(j=0;j<5;j++)
        {
            totalloc=totalloc+allocation[j][i];
        }
        available [i]=total_res[i]-totalloc;
        work[i]=available[i];
    }
    printf("\n Allocated resources:\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",allocation[i][j]);
        }
        printf("\n");
    }
    printf("\n Maximum resources:\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",max[i][j]);
        }
        printf("\n");
    }
    printf("\nNeeded resources:\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d",need[i][j]);
        }
        printf("\n");
    }
    printf("\nAvailable resources:");
    for(i=0;i<3;i++)
    {
        printf("%d",available[i]);
    }
    printf("\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<3;j++)
        {
            if(finish[i]=='f' && need[i][j]<=work[j])
            {
                state=1;
            }
            else
            {
                state=0;
                break;
            }
        }
        if(state==1)
        {
            for(j=0;j<3;j++)
            {
                work[j]=work[j]+allocation[i][j];
            }
            finish[i]='t';
            safe[value]=i;
            ++value;
        }
        if(i==4) 
        {
            if(value=5)
            {
                break;
            }
            else
            {
                i=-1;
            }
        }
    }
    printf("\nsafe states are:");
    for(i=0;i<5;i++)
    {
        printf("p %d ",safe[i]);
    }
    return 0;
}
