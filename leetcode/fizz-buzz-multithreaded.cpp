// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/fizz-buzz-multithreaded/description/
// Date: 18th Feb, 2023
// Tags: concurrency, thread, semaphore

class FizzBuzz {
private:
    int n;
    int i;
    pthread_cond_t cv;
    pthread_mutex_t lock; 

public:
    FizzBuzz(int n) {
        this->n = n;
        pthread_cond_init(&cv, NULL);
        pthread_mutex_init(&lock, NULL);
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        pthread_mutex_lock(&lock);
        while(i <= n) {
            while(i <= n && !(i%3==0 && i%5!=0)) {
                pthread_cond_wait(&cv, &lock);
            }
            if(i <= n) printFizz();
            i++;
            pthread_cond_broadcast(&cv);
        }
        pthread_mutex_unlock(&lock);
        
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        pthread_mutex_lock(&lock);
        while(i <= n) {
            while(i <= n && !(i%5==0 && i%3!=0)) {
                pthread_cond_wait(&cv, &lock);
            }
            if(i <= n) printBuzz();
            i++;
            pthread_cond_broadcast(&cv);
        }
        pthread_mutex_unlock(&lock);
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        pthread_mutex_lock(&lock);
        while(i <= n) {
            while(i <= n && !(i%5==0 && i%3==0)) {
                pthread_cond_wait(&cv, &lock);
            }
            if(i <= n) printFizzBuzz();
            i++;
            pthread_cond_broadcast(&cv);
        }
        pthread_mutex_unlock(&lock);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        pthread_mutex_lock(&lock);
        while(i <= n) {
            while(i <= n && !(i%5!=0 && i%3!=0)) {
                pthread_cond_wait(&cv, &lock);
            }
            if(i <= n) printNumber(i);
            i++;
            pthread_cond_broadcast(&cv);
        }
        pthread_mutex_unlock(&lock);
    }
};
