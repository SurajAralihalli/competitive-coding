// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/word-search/
// Date: 31th May, 2021
// Tags: backtracking, recursion, dfs


class Solution {
public:
    
    vector<vector<int>> used;
    bool flag;
    bool exist(vector<vector<char>>& board, string word) {
        
         int m = board.size();
         int n = board[0].size();
        
         used.assign(m, vector<int> (n,0));
         flag = false;
        
         for(int i=0;i<m;i++)
         {
             for(int j=0;j<n;j++)
             {
                 dfs(i, j, 0, board, word);
             }
        }
        return flag;
    }
    
    void dfs(int i, int j, int index, vector<vector<char>>& board,string& word)
    {
        int m = board.size();
        int n = board[0].size();
        
        if(index==word.size())
        {
            flag = true;
        }
        else if(index>word.size() || i>=m || i<0 || j>=n || j<0 || used[i][j]==1 || board[i][j]!=word[index] || flag==true)
        {
            return;
        }
        else
        {
            used[i][j]=1;
            
            dfs(i-1, j, index+1, board, word);
            dfs(i, j-1, index+1, board, word);
            dfs(i+1, j, index+1, board, word);
            dfs(i, j+1, index+1, board, word);
            
            used[i][j]=0;
        }
    
    }
};
