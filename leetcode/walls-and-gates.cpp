// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/walls-and-gates/
// Date: 22nd Oct, 2022
// Tags: graph, bfs

class Solution {
public:
    vector<vector<int>> visited;
    int n;
    int m;
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        n = rooms.size();
        m = rooms[0].size();
        visited.assign(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(rooms[i][j]==0)
                {
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        
        int count = q.size();
        int dist = 0;
        
        while(!q.empty())
        {
            for(int i=0;i<count;i++)
            {
                auto top = q.front();
                q.pop();
                int r = top.first;
                int c = top.second;
                
                visited[r][c] = 1;
                rooms[r][c] = min(rooms[r][c], dist);
                
                if(r+1<n && visited[r+1][c] == 0 && rooms[r+1][c]!=-1)
                {
                    q.push({r+1,c});
                    visited[r+1][c] = 1;
                }
                if(r-1>=0 && visited[r-1][c] == 0 && rooms[r-1][c]!=-1)
                {
                     q.push({r-1,c});
                     visited[r-1][c] = 1;
                }
                if(c+1<m && visited[r][c+1] == 0 && rooms[r][c+1]!=-1)
                {
                     q.push({r,c+1});
                     visited[r][c+1] = 1;
                }
                if(c-1>=0 && visited[r][c-1] == 0 && rooms[r][c-1]!=-1)
                {
                     q.push({r,c-1});
                    visited[r][c-1] = 1;
                }
            }
            
            dist++;
            count = q.size();
        }  
    }
};
