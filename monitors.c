
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#define MAX_PORTS 5
int open_ports=0;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t can_open=PTHREAD_COND_INITIALIZER;
pthread_cond_t can_close=PTHREAD_COND_INITIALIZER;
void * open_port(void* arg)
{
    pthread_mutex_lock(&mutex);
    while(open_ports>=MAX_PORTS)
    {
        printf("maximum ports opened.waiting to open a port...\n");
        pthread_cond_wait(&can_open,&mutex);
    }
    open_ports++;
    printf("port opened.current open ports:%d\n",open_ports);
    pthread_cond_signal(&can_close);
    pthread_mutex_unlock(&mutex);
    return NULL;
}
void *close_port(void *arg)
{
    pthread_mutex_lock(&mutex);
    while(open_ports<=0)
    {
        printf("No open ports to close.waiying...\n");
        pthread_cond_wait(&can_close,&mutex);
    }
    open_ports--;
    printf("port closed.current open ports:%d\n",open_ports);
    pthread_cond_signal(&can_open);
    pthread_mutex_unlock(&mutex);
    return NULL;
    }
int main()
    {
        pthread_t threads[20];
        int i;
        for(i=0;i<10;i++)
        {
            pthread_create(&threads[i],NULL,open_port,NULL);
        }
        for(i=0;i<5;i++)
        {
            pthread_create(&threads[10+i],NULL,close_port,NULL);
        }
        for(i=0;i<15;i++)
        {
            pthread_join(threads[i],NULL);
        }
        pthread_mutex_destroy(&mutex);
        pthread_cond_destroy(&can_open);
        pthread_cond_destroy(&can_close);
        return 0;
    }
