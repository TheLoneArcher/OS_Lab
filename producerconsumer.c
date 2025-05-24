#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define MAX 5
int buffer[MAX], produceIndex = 0, consumeIndex = 0;
sem_t empty, full, mutex;
void* producerThread(void* arg) {
    int item;
    while (1) {
        item = rand() % 100;
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[produceIndex] = item;
        printf("Produced: %d\n", item);
        produceIndex = (produceIndex + 1) % MAX;
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
}
void* consumerThread(void* arg) {
    int item;
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);
        item = buffer[consumeIndex];
        printf("Consumed: %d\n", item);
        consumeIndex = (consumeIndex + 1) % MAX;
        sem_post(&mutex);
        sem_post(&empty);
        sleep(1);
    }
}
int main() {
    pthread_t producerId, consumerId;
    sem_init(&empty, 0, MAX); sem_init(&full, 0, 0); sem_init(&mutex, 0, 1);
    pthread_create(&producerId, NULL, producerThread, NULL);
    pthread_create(&consumerId, NULL, consumerThread, NULL);
    pthread_join(producerId, NULL); pthread_join(consumerId, NULL);
    sem_destroy(&empty); sem_destroy(&full); sem_destroy(&mutex);
    return 0;
}