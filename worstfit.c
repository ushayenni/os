#include <stdio.h>
#include <stdlib.h>
void worstFit(int blockSize[], int m, int processSize[], int n)
{
int allocation[n];
int i,j;
for ( i = 0; i < n; i++)
allocation[i] = - 1;
for ( i = 0; i < n; i++)
{
int worstIdx = - 1;
for ( j = 0; j < m; j++)
{
if (blockSize [j] >= processSize[i])
{
if (worstIdx == - 1 || blockSize[j] > blockSize [worstIdx])
worstIdx = j;
}
}
if(worstIdx != - 1) {
allocation[i] = worstIdx;
blockSize [worstIdx]= blockSize[worstIdx] -processSize[i];
}
}
printf ("Process No. \tProcess Size \tBlock No. \n");
for ( i = 0; i < n; i++) {
printf("%d\t\t%d\t\t", i, processSize[i]);
if (allocation[i] != - 1)
printf("%d\n", allocation[i]);
else
printf("Not Allocated\n");
}
}
void main ()
{
int i,bs,p,blockSize[10], processSize[10];
printf ("Enter no .of blocks:");
scanf("%d",&bs);
for(i=0;i<bs; i++)
{
printf("Enter %d block size:", i);
scanf("%d", &blockSize[i]);
}
printf ("Enter no.of process:");
scanf("%d",&p);
for(i=0;i<p;i++)
{
printf ("Enter %d process size:", i);
scanf ("%d", &processSize[i]);
}
worstFit (blockSize, bs, processSize, p);
}
