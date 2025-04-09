#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <signal.h>
#define MAX 5        
#define TOTAL 10     
int buffer[MAX];
int in = 0, out = 0;  
sem_t empty, full;
pthread_mutex_t mutex;
int running = 1;  
void handle_signal(int sig) {
    printf("\nReceived signal %d. Cleaning up and exiting...\n", sig);
    running = 0; 
}
void* producer(void* param) {
    int item;
    for (int i = 0; i < TOTAL && running; i++) {
        item = rand() % 100;  
        sem_wait(&empty); 
        pthread_mutex_lock(&mutex);
        buffer[in] = item; 
        printf("Produced: %d at index %d\n", item, in);
        in = (in + 1) % MAX;  
        pthread_mutex_unlock(&mutex);
        sem_post(&full);  
        sleep(1);  
}
    return NULL;
}
void* consumer(void* param) {
    int item;
    for (int i = 0; i < TOTAL && running; i++) {
        sem_wait(&full);  
        pthread_mutex_lock(&mutex);
        item = buffer[out];  
        printf("Consumed: %d from index %d\n", item, out);
        out = (out + 1) % MAX; 
        pthread_mutex_unlock(&mutex);
        sem_post(&empty); 
        sleep(1);  
    }
    return NULL;
}
int main() {
    srand(time(NULL));  
    signal(SIGINT, handle_signal);  
    pthread_t prod, cons;
      sem_init(&empty, 0, MAX);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    printf("Program finished successfully!\n");
    return 0;
}
