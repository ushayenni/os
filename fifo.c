
#include<stdio.h>
int main(){
    int i,j,n,a[50],frame[10],no,k,avail,count=0;
    printf("\n enter no of pages:\n");
    scanf("%d",&n);
    printf("\n eneter the page number:\n");
    for(i=0;i<=n;i++)
    scanf("%d",&a[i]);
    printf("Enter no of frames:");
    scanf("%d",&no);
    for(i=0;i<no;i++)
        frame[i]=-1;
    j=0;
    printf("\t ref string \t pages frames\n");
    for(i=0;i<=n;i++){
        printf("%d\t\t\t",a[i]);
        avail=0;
        for(k=0;k<no;k++)
            if(frame[k]==a[i])
            avail=1;
        if(avail==0){
            frame[j]=a[i];
            j=j+1%no;
            count++;
            for(k=0;k<no;k++)
                printf("%d\t",frame[k]);
        }
        printf("\n");
    }
    printf("page fault is %d",count);
    return 0;
}
