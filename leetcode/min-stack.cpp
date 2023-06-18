// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/min-stack/
// Date: 25th September, 2022
// Tags: stack, design

class MinStack {
public:
    stack<int> stk;
    stack<int> mstk;
    MinStack() {
       
    }
    
    void push(int val) {
        stk.push(val);
        if(mstk.empty() || mstk.top()>=val) mstk.push(val);
    }
    
    void pop() {
        if(mstk.top()==stk.top()) mstk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
