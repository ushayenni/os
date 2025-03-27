#include <stdio.h>
#include <stdlib.h>

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
   
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
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

    worstFit(blockSize, bs, processSize, p);

    return 0;
}
worst fit

teja saladi, 10:10 AM
Enter no. of blocks: 5
Enter 0 block size: 100
Enter 1 block size: 500
Enter 2 block size: 200
Enter 3 block size: 300
Enter 4 block size: 600
Enter no. of processes: 4
Enter 0 process size: 212
Enter 1 process size: 417
Enter 2 process size: 112
Enter 3 process size: 426
Process No. Process Size Block No.
0 212 4
1 417 1
2 112 4
3 426 Not Allocated
aim: implement the memory allocation method for fixed partition of 
worst fit


ReplyForward

teja saladi, 10:14 AM
#include <stdio.h>
#include <stdlib.h>

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
   
    for (int i = 0; i < n; i++)
        allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
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

    worstFit(blockSize, bs, processSize, p);

    return 0;
}
