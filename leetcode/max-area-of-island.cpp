// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/max-area-of-island/
// Date: 10th October, 2022
// Tags: graph, dfs

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        int max_area = 0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    int area=0;
                    dfs(i,j,grid,visited,area);
                    max_area= max(max_area,area);
                    
                }
            }
        }
        return max_area;
        
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited,int& area)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        if(i>=m || i<0 || j>=n || j<0 || visited[i][j]==1 || grid[i][j]==0) 
        {
            return;
        }
        else
        {
            visited[i][j]=1;
            area++;
            
            dfs(i-1,j,grid,visited,area);
            dfs(i+1,j,grid,visited,area);
            dfs(i,j-1,grid,visited,area);
            dfs(i,j+1,grid,visited,area);
            return;
        }
    }
};
