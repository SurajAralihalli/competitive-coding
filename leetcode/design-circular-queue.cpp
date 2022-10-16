// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/design-circular-queue/
// Date: 16th October, 2022
// Tags: queue, array, circular-queue

class MyCircularQueue {
public:
    vector<int> q;
    int head;
    int tail;
    int count;
    int k;
    
    MyCircularQueue(int k) {
        q.assign(k, 0);
        this->head =0;
        this->tail =0;
        this->count =0;
        this->k = k;
        
    }
    
    bool enQueue(int value) {
        if(!isFull())
        {
            q[tail] = value;
            tail = (tail+1)%k;
            count++;
            
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty())
        {
            head = (head+1)%k;
            count--;
            return true;
        }
        return false;
        
    }
    
    int Front() {
        if(!isEmpty())
        {
            return q[head];
        }
        return -1;
    }
    
    int Rear() {
        if(!isEmpty())
        {
            return q[(tail+k-1)%k];
        }
        return -1;
    }
    
    bool isEmpty() {
        if(count==0)
        {
            return true;
        }
        
        return false;
    }
    
    bool isFull() {
        if(count==k)
        {
            return true;
        }
        
        return false;
        
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
