// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/print-in-order/description/
// Date: 18th Feb, 2023
// Tags: concurrency, thread, semaphore 

#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

class Foo {
public:
    sem_t f;
    sem_t s;
    sem_t t;
    Foo() {
        sem_init(&f, 0, 1);
        sem_init(&s, 0, 0);
        sem_init(&t, 0, 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        sem_wait(&f);
        printFirst();
        sem_post(&s);
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        sem_wait(&s);
        printSecond();
        sem_post(&t);
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        sem_wait(&t);
        printThird();
        sem_post(&f);
    }
};
