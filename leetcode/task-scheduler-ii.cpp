// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/task-scheduler-ii/description/
// Date: 21st February, 2022
// Tags: queue, design

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        // {count, name}
        queue<int> pReadyQueue;
        // {readyTime, {count, name}}
        unordered_map<unsigned long, unsigned long> readyTime;
                
    
        
        // build pReadyQueue
        for(auto task:  tasks)
        {
            pReadyQueue.push(task);
            readyTime[task] = 0;
        }
        
        unsigned long timer=0;
        
        while(!pReadyQueue.empty())
        {
            
            auto task = pReadyQueue.front();
            if(readyTime[task] > timer) {
                // cout << "case1: #" << task << "# " << timer << " " << readyTime[task] << "@" << endl;
                unsigned long waitDiff = readyTime[task] - timer;

                timer += waitDiff;
                continue;
            }
            else {
                // cout << "case2: #" << task << "# " << timer << " " << readyTime[task] << "@"<< endl;
                readyTime[task] = timer+space+1;

                timer++;
                pReadyQueue.pop();
            }
            
        }
        
        return timer;
    }
};
