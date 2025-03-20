#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define NUM_THREADS 5
void *print_thread_id(void *thread_id)
{
    long tid=(long)thread_id;
    printf("Thread %ld is running\n",tid);
    pthread_exit(NULL);
}
int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for(t=0;t<NUM_THREADS;t++)
    {
        printf("Creating thread %ld\n",t);
        rc=pthread_create(&threads[t],NULL,print_thread_id,(void *)t);
        if(rc)
        {
            printf("Error: Unable to create thread %ld,return code:%d\n",t,rc);
            exit(-1);
        }
    }
    for(t=0;t<NUM_THREADS;t++)
    {
        pthread_join(threads[t],NULL);
    }
    printf("ALL threads completed execution.\n");
    pthread_exit(NULL);
}
