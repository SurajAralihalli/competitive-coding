// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/surrounded-regions/
// Date: 10th Oct, 2022
// Tags: graph, dfs

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> reached(n, vector<int>(m,0));
        
        for(int c=0;c<m;c++)
        {
            dfs(board, reached, 0, c);
            dfs(board, reached, n-1, c);
        }
        
        for(int r=0;r<n;r++)
        {
            dfs(board, reached, r, 0);
            dfs(board, reached, r, m-1);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(reached[i][j]==1)
                {
                    board[i][j]='O';
                }
                else
                {
                    board[i][j]='X';
                }
            }
        }
        
    }
    
    void dfs(vector<vector<char>>& board,  vector<vector<int>>& reached, int i, int j)
    {
        int n = board.size();
        int m = board[0].size();
        if(i>=n || i<0 || j>=m || j<0 || reached[i][j]==1 || board[i][j]!='O')
        {
            return;
        }
        else
        {
            reached[i][j]=1;
            dfs(board, reached, i+1, j);
            dfs(board, reached, i-1, j);
            dfs(board, reached, i, j+1);
            dfs(board, reached, i, j-1);
        }
    }
};
