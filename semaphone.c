 #include<stdio.h>
 #include<pthread.h>
 #include<semaphore.h>
 #include<unistd.h>
 #define MAX_PORTS 5
 int open_ports=0;
 sem_t mutex;
 void *open_port(void*arg)
 {
     sem_wait(&mutex);
     if(open_ports < MAX_PORTS)
     {
         open_ports++;
         printf("port opened.current open ports:%d\n",open_ports);
     }
     else
     {
         printf("cannot open more ports.maximum limit reached.\n");
     }
     sem_post(&mutex);
     return NULL;
 }
 void * close_port(void*arg)
 {
     sem_wait(&mutex);
     if(open_ports>0)
     {
         open_ports--;
         printf("port closed. current open ports:%d\n",open_ports);
     }
     else{
         printf("no ports are open to close.\n");
     }
     sem_post(&mutex);
     return NULL;
 }
 int main()
     {
         pthread_t threads[20];
         int i;
         sem_init(&mutex,0,1);
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
         sem_destroy(&mutex);
         return 0;
     }
