// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/graph-valid-tree/
// Date: 22nd Oct, 2022
// Tags: graph, dfs, topo-sort, toposort

class Solution {
public:
    unordered_map<int,vector<int>> map;
    vector<int> visited;
    vector<int> instack;
    vector<int> order;
    bool loopFree;
    bool validTree(int n, vector<vector<int>>& edges) {
        for(auto edge: edges)
        {
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        
        visited.assign(n,0);
        instack.assign(n,0);
        
        loopFree = true;
        dfs(0, -1);
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0) return false;
        }
        
        return loopFree;
    }
    
    
    void dfs(int v, int prev)
    {
        if(instack[v]==1)
        {
            loopFree=false;
            return;
        }
        else if(visited[v]==1)
        {
            return;
        }
        else
        {
            visited[v]=1;
            instack[v]=1;
            
            for(auto adj: map[v])
            {
                if(adj!=prev) dfs(adj, v);
            }
            
            instack[v]=0;
        }
    }
};
