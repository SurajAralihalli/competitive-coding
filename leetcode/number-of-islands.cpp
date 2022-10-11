// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/number-of-islands/
// Date: 27th May, 2021
// Tags: dfs, graph, union-find

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        
        vector<vector<int>> visited(n, vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && visited[i][j]==0)
                {
                    count++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i>=n || i<0 || j>=m || j<0 || visited[i][j]==1 || grid[i][j]=='0')
        {
            return;
        }
        else
        {
            visited[i][j]=1;
            dfs(grid, visited, i+1, j);
            dfs(grid, visited, i-1, j);
            dfs(grid, visited, i, j+1);
            dfs(grid, visited, i, j-1);
        }
    }
};
