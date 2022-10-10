// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/rotting-oranges/
// Date: 10th Oct, 2022
// Tags: graph, bfs

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int freshO = 0;
        
        vector<vector<int>> visited(n, vector<int> (m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
                else if(grid[i][j]==1)
                {
                    freshO++;
                }
                    
            }
        }
        int timer =0;
        int count = q.size();
        while(!q.empty())
        {
            if(freshO==0)
            {
                break;
            }
            
            timer++;

            for(int i=0;i<count;i++)
            {
                auto coord = q.front();
                q.pop();
                int x = coord.first;
                int y = coord.second;
                
                if(x+1 < n && visited[x+1][y] == 0 && grid[x+1][y] == 1)
                {
                    freshO--;
                    q.push({x+1,y});
                    visited[x+1][y] = 1;
                }
                if(x-1 >= 0 && visited[x-1][y] == 0 && grid[x-1][y] == 1)
                {
                    freshO--;
                    q.push({x-1,y});
                    visited[x-1][y] = 1;
                }
                if(y+1 < m && visited[x][y+1] == 0 && grid[x][y+1] == 1)
                {
                    freshO--;
                    q.push({x,y+1});
                    visited[x][y+1] = 1;
                }
                if(y-1 >= 0 && visited[x][y-1] == 0 && grid[x][y-1] == 1)
                {
                    freshO--;
                    q.push({x,y-1});
                    visited[x][y-1] = 1;
                }
            }
              
           
            count = q.size();
        }
        
        return freshO==0?timer:-1;
        
    }
    
};
