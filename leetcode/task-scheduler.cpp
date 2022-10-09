// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/task-scheduler/
// Date: 8th Oct, 2022
// Tags: heap, priority-queue

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // {count, name}
        priority_queue<pair<int,char>> pReadyQueue;
        // {readyTime, {count, name}}
        queue<pair<int, pair<int,char>>> nonReadyQueue;
        
        unordered_map<char,int> map;
        
        for(char pname: tasks)
        {
            map[pname]++;
        }
        
        // build pReadyQueue
        for(auto task:  map)
        {
            pReadyQueue.push({task.second, task.first});
        }
        
        int timer=0;
        
        while(!pReadyQueue.empty() || !nonReadyQueue.empty())
        {
            
            if(!pReadyQueue.empty())
            {
                auto task = pReadyQueue.top();
                pReadyQueue.pop();
                task.first--;
                
                // if count is 0
                if(task.first!=0)
                {
                    nonReadyQueue.push({timer+n,task});
                }
            }
            
            if(!nonReadyQueue.empty())
            {
                auto taskDetail = nonReadyQueue.front();
                auto task = taskDetail.second;
                auto readyTime = taskDetail.first;
                
                if(readyTime<=timer)
                {
                    nonReadyQueue.pop();
                    pReadyQueue.push(task);
                }
            }
            timer++;   
        }
        
        return timer;
    }
};
