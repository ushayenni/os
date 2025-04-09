#include <stdio.h>
#include <stdlib.h>
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++)
        allocation[i] = -1;
    for (int i = 0; i < n; i++) {
        int firstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                firstIdx = j;
                break;
            }
        }
        if (firstIdx != -1) {
            allocation[i] = firstIdx;
            blockSize[firstIdx] -= processSize[i];
        }
    }
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i]);
        else
            printf("Not Allocated\n");
    }
}
int main() {
    int i, bs, p, blockSize[10], processSize[10];
    printf("Enter no. of blocks: ");
    scanf("%d", &bs);
    for (i = 0; i < bs; i++) {
        printf("Enter %d block size: ", i);
        scanf("%d", &blockSize[i]);
    }
    printf("Enter no. of processes: ");
    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        printf("Enter %d process size: ", i);
        scanf("%d", &processSize[i]);
    }
    firstFit(blockSize, bs, processSize, p);
    return 0;
}
