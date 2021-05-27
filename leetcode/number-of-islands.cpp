// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/number-of-islands/
// Date: 27th May, 2021
// Tags: dfs, graph, union-find

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mark;
        mark.assign(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && mark[i][j]==0)
                {
                    count++;
                    visit(i,j,grid,mark);
                }
            }
        }
        return count;
    }
    
    static void visit(int i,int j,vector<vector<char>>& grid, vector<vector<int>>& mark)
    {
        
      
        if(mark[i][j]==1) {return;}
        mark[i][j]=1;
        if(grid[i][j]=='0') {return;}
        int m = grid.size();
        int n = grid[0].size();
        if(i-1>=0)
        {
            visit(i-1,j, grid, mark);
        }
        if(j-1>=0)
        {
            visit(i,j-1, grid, mark);
        }
        if(i+1<m)
        {
            visit(i+1,j, grid, mark);
        }
        if(j+1<n)
        {
            visit(i,j+1, grid, mark);
        }
        return;
    }
        
};