// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/web-crawler-multithreaded/description/
// Date: 19th Feb, 2023
// Tags: concurrency, thread, mutex

#include <pthread.h>
#include <semaphore.h>
#include <bits/stdc++.h>
using namespace std;


pthread_t t1, t2;
pthread_mutex_t lck;
pthread_cond_t cv;
int id;
int n;
int otherThreadId;


struct threadId {
    int id;
};

void* printOtherThreadId(void* arg) {
    int myId = ((threadId*) arg)->id;
    for(int i=0;i<n;i++) {
        pthread_mutex_lock(&lck);
        while(otherThreadId == myId) {
            pthread_cond_wait(&cv, &lck);
        }

        cout << otherThreadId << endl;
        otherThreadId = myId;

        pthread_cond_signal(&cv);
        pthread_mutex_unlock(&lck);
    }
    
    return NULL;
}

int main() {
    pthread_mutex_init(&lck, NULL);
    pthread_cond_init(&cv, NULL);
    
    otherThreadId = 1;
    n=10;

    threadId* t1_id = new threadId();
    threadId* t2_id = new threadId();

    t1_id->id = 1;
    t2_id->id = 2;

    pthread_create(&t1, NULL, printOtherThreadId, (void*)t1_id);
    pthread_create(&t2, NULL, printOtherThreadId, (void*)t2_id);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    delete t1_id;
    delete t2_id;
    
    return 0;

}
