// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/design-bounded-blocking-queue/description/
// Date: 18th Feb, 2023
// Tags: concurrency, thread, semaphore, producer-consumer

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

class BoundedBlockingQueue {
public:
    list<int> q;
    sem_t empty;
    sem_t full;
    pthread_mutex_t lock;
    BoundedBlockingQueue(int capacity) {
        sem_init(&empty, 0, capacity);
        sem_init(&full, 0, 0);
        pthread_mutex_init(&lock, NULL);
    }
    
    void enqueue(int element) {
        sem_wait(&empty);
        pthread_mutex_lock(&lock);
        q.push_front(element);
        pthread_mutex_unlock(&lock);
        sem_post(&full);
    }
    
    int dequeue() {
        int value;
        sem_wait(&full);
        pthread_mutex_lock(&lock);
        value = q.back();
        q.pop_back();
        pthread_mutex_unlock(&lock);
        sem_post(&empty);

        return value;
    }
    
    int size() {
        int value;
        pthread_mutex_lock(&lock);
        value = q.size();
        pthread_mutex_unlock(&lock);
        return value;
    }
};
