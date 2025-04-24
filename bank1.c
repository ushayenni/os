#include<stdio.h>
#include<stdlib.h>
int main(){
    int al[100][100],need[100][100],max[100][100],av[100],c=0,f[100];
    int sum[100]={0};
    int m,n;
    printf("Enter no of processes: ");
    scanf("%d",&m);
    printf("Enter no of resources: ");
    scanf("%d",&n);

    printf("Enter allocation values: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        scanf("%d",&al[i][j]);
        sum[j]+=al[i][j];
        }
    }

    printf("Enter Max values: \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        scanf("%d",&max[i][j]);
    }

    printf("Enter available values: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&av[i]);
        sum[i]+=av[i];
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        need[i][j]=max[i][j]-al[i][j];
    }

    printf("Need values are : \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            printf("%d ",need[i][j]);
        printf("\n");
    }

    for(int i=0;i<m;i++){
        f[i]=0;
    }
    printf("Total resources: \n");
    for(int i=0;i<n;i++){
        printf("%d ",sum[i]);
    }
    printf("\nSafe sequence: ");
    while(c<m){
        for(int i=0;i<m;i++){
            int flag=1;
            if(f[i]==0){
            for(int j=0;j<n;j++){
                if(need[i][j]>av[j]){
                flag=0;
                break;
                }
            }
            if(flag==1){
                printf("p%d ",i);
                c++;
                for(int t=0;t<n;t++){
                    av[t]+=al[i][t];
                }
                f[i]=1;
            }
        }
    }
    }
}
