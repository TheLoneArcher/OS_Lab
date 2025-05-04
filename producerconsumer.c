#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_CAPACITY 5

int sharedBuffer[BUFFER_CAPACITY];
int produceIndex = 0;
int consumeIndex = 0;

sem_t emptySlots;
sem_t filledSlots;
sem_t bufferMutex;

void* producerThread(void* arg) {
    int item;
    while (1) {
        item = rand() % 100;
        sem_wait(&emptySlots);
        sem_wait(&bufferMutex);
        sharedBuffer[produceIndex] = item;
        printf("Produced: %d\n", item);
        produceIndex = (produceIndex + 1) % BUFFER_CAPACITY;
        sem_post(&bufferMutex);
        sem_post(&filledSlots);
        sleep(1);
    }
}

void* consumerThread(void* arg) {
    int item;
    while (1) {
        sem_wait(&filledSlots);
        sem_wait(&bufferMutex);
        item = sharedBuffer[consumeIndex];
        printf("Consumed: %d\n", item);
        consumeIndex = (consumeIndex + 1) % BUFFER_CAPACITY;
        sem_post(&bufferMutex);
        sem_post(&emptySlots);
        sleep(1);
    }
}

int main() {
    pthread_t producerId, consumerId;

    sem_init(&emptySlots, 0, BUFFER_CAPACITY);
    sem_init(&filledSlots, 0, 0);
    sem_init(&bufferMutex, 0, 1);

    pthread_create(&producerId, NULL, producerThread, NULL);
    pthread_create(&consumerId, NULL, consumerThread, NULL);

    pthread_join(producerId, NULL);
    pthread_join(consumerId, NULL);

    sem_destroy(&emptySlots);
    sem_destroy(&filledSlots);
    sem_destroy(&bufferMutex);

    return 0;
}