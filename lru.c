#include <stdio.h>
int main() {
    int total_frames, total_pages, hit = 0;
    int frame[10], pages[25], arr[25] = {0}, time[25] = {0};
    int m, n, temp, flag, k, minimum_time;
    printf("Enter the number of pages: ");
    scanf("%d", &total_pages);
    printf("Enter total number of frames: ");
    scanf("%d", &total_frames);
    for (m = 0; m < total_frames; m++) {
        frame[m] = -1;
    }
    printf("Enter values of reference string:\n");
    for (m = 0; m < total_pages; m++) {
        printf("Enter value no.[%d]: ", m + 1);
        scanf("%d", &pages[m]);
    }
    printf("\n");
    for (m = 0; m < total_pages; m++) {
        arr[pages[m]]++;        
        time[pages[m]] = m;      
        flag = 1;
                for (n = 0; n < total_frames; n++) {
            if (frame[n] == pages[m]) {
                hit++;
                flag = 0; 
                break;
            } else if (frame[n] == -1) {
                frame[n] = pages[m];
                flag = 0;
                break;
            }
        }
                if (flag) {
            k = frame[0];
            for (n = 1; n < total_frames; n++) {
                if (arr[frame[n]] < arr[k] || 
                   (arr[frame[n]] == arr[k] && time[frame[n]] < time[k])) {
                    k = frame[n];
                }
            }
                     for (n = 0; n < total_frames; n++) {
                if (frame[n] == k) {
                    arr[frame[n]] = 0;
                    frame[n] = pages[m];
                    break;
                }
            }
        }
              for (n = 0; n < total_frames; n++) {
            if (frame[n] != -1)
                printf("%d\t", frame[n]);
            else
                printf("-\t");
        }
        printf("\n");
    }
    printf("Page Hit:\t%d\n", hit);
    printf("Page Fault:\t%d\n", total_pages - hit);
    return 0;
}
