#include<stdio.h>
#define max 20
int main(){
    int bt[max], at[max], ft[max], wt[max], tat[max];
    int i, j, x = 0, y = 0, z = 0, min = 0, temp1, temp2, k, l;
    int n;
    float t, u;
    printf("Enter number of processes to be executed:\n");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        printf("Enter the burst time for process-%d:\n", i);
        scanf("%d", &bt[i]);
        printf("Enter the arrival time for process-%d:\n", i);
        scanf("%d", &at[i]);
    }
    for(i = 1; i < n; i++) {
        for(j = i + 1; j <= n; j++) {
            if(at[i] > at[j]) {
                temp1 = at[i];
                at[i] = at[j];
                at[j] = temp1;
                temp2 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp2;
            }
            else if(at[i] == at[j] && bt[i] > bt[j]) {
                temp1 = at[i];
                at[i] = at[j];
                at[j] = temp1;
                temp2 = bt[i];
                bt[i] = bt[j];
                bt[j] = temp2;
            }
        }
    }
    for(i = 1; i <= n; i++) {
        min = min + bt[i];  
        for(j = i + 1; at[j] <= min; j++) {
            for(k = j + 1; at[k] <= min; k++) {
                if(bt[k] < bt[j]) {
                    temp1 = bt[k];
                    bt[k] = bt[j];
                    bt[j] = temp1;
                    temp2 = at[k];
                    at[k] = at[j];
                    at[j] = temp2;
                }
            }
        }
    }
    for(i = 1; i <= n; i++) {
        x = x + bt[i];
        ft[i] = x;
        if(i == 1)
            wt[i] = 0;
        else
            wt[i] = ft[i - 1] - at[i];

        tat[i] = bt[i] + wt[i];
    }
    for(i = 1; i <= n; i++) {
        y = y + tat[i];
        z = z + wt[i];  
    }
    for(i = 1; i <= n; i++) {
        printf("\nProcess:%d --> at: %d\n, bt: %d\n, ft: %d\n,wt: %d\n,tat: %d\n",
                i, at[i], bt[i], ft[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time: %.2f", (float)z/n);
    printf("\nAverage Turnaround Time: %.2f", (float)y/n);

    return 0;
}
