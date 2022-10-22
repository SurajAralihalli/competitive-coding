// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
// Date: 22nd Oct, 2022
// Tags: graph, dfs

class Solution {

public:
    unordered_map<int, vector<int>> map;
    vector<int> visited;
    int countComponents(int n, vector<vector<int>>& edges) {
        visited.assign(n,0);
        int count=0;
        for(auto edge:edges)
        {
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        
        for(int i=0;i<n;i++)
        {
           
           if(visited[i]==0) 
           {
               count++;
               dfs(i);
           }
        }
        
        return count;
    }
    
    void dfs(int index)
    {
        if(visited[index]==1) return;
        visited[index]=1;
        for(auto adj: map[index])
        {
            dfs(adj);
        }
    }
};
