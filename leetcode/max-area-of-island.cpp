// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/max-area-of-island/
// Date: 1st June, 2021
// Tags: dfs

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited;
        int max_area=0;
        visited.assign(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && visited[i][j]==0)
                {
                    int area=0;
                    help(i,j,grid,visited,area);
                    max_area= max(max_area,area);
                    
                }
            }
        }
        return max_area;
        
    }
    static void help(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited,int& area)
    {
        if(visited[i][j]) {return;}
        visited[i][j]=1;
        if(grid[i][j])
        {
            int m = grid.size();
            int n = grid[0].size();
            area++;
            if(i-1>=0)
            {
                help(i-1,j,grid,visited,area);
            }
            if(j-1>=0)
            {
                help(i,j-1,grid,visited,area);
            }
            if(i+1<m)
            {
                help(i+1,j,grid,visited,area);
            }
            if(j+1<n)
            {
                help(i,j+1,grid,visited,area);
            }
        }
        return;
    }
};