// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/island-perimeter
// Date: 8th October, 2021
// Tags: dfs, map, island-maze, mat

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector< vector<int> > explored;
        int m = grid.size();
        int n = grid[0].size();
        explored.assign(m,vector<int>(n,0));
        int perimeter =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool flag=false;
                if(grid[i][j]==1)
                {
                    find_perimeter(grid,explored, perimeter, i,j );
                    flag=true;
                    break;
                }
                if(flag)
                {
                    break;
                }
            }
        }
        
        return perimeter;
        
    }
    
    void find_perimeter(vector<vector<int>>& grid,vector< vector<int> >&explored,int& perimeter, int i, int j )
    {
        if(explored[i][j]) return;
        
        explored[i][j]=1;
        
        int m = grid.size();
        int n = grid[0].size();
        
        if(grid[i][j]==1)
        {
            int p =0;
            if(j-1>=0 && grid[i][j-1] && explored[i][j-1])
            {
                p--;
            }
            else
            {
                p++;
                
            }
            
            if(j+1<n && grid[i][j+1] && explored[i][j+1])
            {
                p--;
            }
            else
            {
                p++;
                
            }
            
            if(i-1>=0 && grid[i-1][j] && explored[i-1][j])
            {
                p--;
            }
            else
            {
                p++;
                
            }
            
            if(i+1<m && grid[i+1][j] && explored[i+1][j])
            {
                p--;
            }
            else
            {
                p++;
                
            }
            
            if(j-1>=0)
                {
                    find_perimeter(grid,explored,perimeter,i,j-1);
                }
            if(j+1<n)
                {
                    find_perimeter(grid,explored,perimeter,i,j+1);
                }
            if(i-1>=0)
                {
                    find_perimeter(grid,explored,perimeter,i-1,j);
                }
            if(i+1<m)
                {
                    find_perimeter(grid,explored,perimeter,i+1,j);
                }
            perimeter+=p;
            
        }
    }
};
