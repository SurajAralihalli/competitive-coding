// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
// Date: 5th Nov, 2022
// Tags: heap, priority-queue, intervals

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), ascOnFirstKey);  
        priority_queue<int, vector<int>, greater<int>> pq; //min heap on end time
        
        int i=0;
        int n=events.size();
        int count = 0;
        //for each day
        for(int d=1; d<=100000; d++)
        {
            // start day == d, add to pq
            while(i<n && events[i][0]==d)
            {
                pq.push(events[i][1]);
                i++;
            }
            
            // pop all missed events - past deadlines
            while(!pq.empty() && pq.top()<d)
            {
                pq.pop();
            }
            
            // pop one event - earliest deadline first
            if(!pq.empty())
            {
                pq.pop();
                count++;
            }
        }
        
        return count;
    }
    
    static bool ascOnFirstKey(vector<int>& event1, vector<int>& event2)
    {
        return event1[0]<event2[0];
    }
};
