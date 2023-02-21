// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/print-foobar-alternately/description/
// Date: 18th Feb, 2023
// Tags: concurrency, thread, mutex 

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

class FooBar {
private:
    int n;
    pthread_cond_t f , b;
    pthread_mutex_t lock;
    bool first;

public:
    FooBar(int n) {
        this->n = n;
        first = true;
        pthread_mutex_init(&lock, NULL);
        pthread_cond_init(&f, NULL);
        pthread_cond_init(&b, NULL);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
            pthread_mutex_lock(&lock);
            while(first != true) {
                pthread_cond_wait(&f, &lock);
            }
            printFoo();
            first = false;
            pthread_cond_signal(&b);
            pthread_mutex_unlock(&lock);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
            pthread_mutex_lock(&lock);
            while(first != false) {
                pthread_cond_wait(&b, &lock);
            }
            printBar();
            first = true;
            pthread_cond_signal(&f);
            pthread_mutex_unlock(&lock);
        }
    }
};
