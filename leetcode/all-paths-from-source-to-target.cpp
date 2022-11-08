// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/all-paths-from-source-to-target/
// Date: 8th Nov, 2022
// Tags: backtracking, dfs

class Solution {
public:
    int dest;
    vector<vector<int>> sol;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dest = graph.size()-1;
        vector<int> path;
        dfs(graph, path, 0);
        return sol;
    }
    
    void dfs(vector<vector<int>>& graph, vector<int>& path, int index)
    {
        if(index==dest)
        {
            path.push_back(dest);
            sol.push_back(path);
            path.pop_back();
            return;
        }
        else if(index>dest)
        {
            return;
        }
        else
        {
            path.push_back(index);
            for(auto i: graph[index])
            {
                dfs(graph, path, i);
            }
            path.pop_back();
        }
    }
};
