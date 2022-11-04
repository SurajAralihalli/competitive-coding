// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/
// Date: 4th Nov, 2022
// Tags: heap

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        priority_queue<int> readyQueue;
        for(int i:milestones)
        {
            readyQueue.push(i);
        }
        int prev = 0;
        long long week = 0;
        while(!readyQueue.empty())
        {
            int t = readyQueue.top();
            readyQueue.pop();
            t--;
            if(prev!=0)
            {
                readyQueue.push(prev);
            }
            prev =t;
            week++;
        }
        return week;
    }
};
