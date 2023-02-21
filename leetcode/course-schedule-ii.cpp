// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/course-schedule-ii/
// Date: 10th July, 2022
// Tags: graph, toposort, dfs

class Solution {
public:
    vector<int> order;
    vector<int> inStack;
    vector<int> visited;
    unordered_map<int, vector<int>> map;
    bool loop = false;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto i: prerequisites)
        {
            map[i[0]].push_back(i[1]);
        }
        inStack.assign(numCourses,0);
        visited.assign(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0)
            {
                dfs(i);
            }
        }
        return loop?vector<int>():order;
        
    }
    
    void dfs(int i)
    {
        if(visited[i]) return;
        visited[i] =1;
        inStack[i] =1;
        for(int adj: map[i])
        {
            if(inStack[adj]) 
            {
                //loop deteced
                loop = true;
            }
            dfs(adj);
        }
        inStack[i] = 0;
        order.push_back(i);
    }
};
