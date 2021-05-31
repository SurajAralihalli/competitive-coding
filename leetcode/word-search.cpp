// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/word-search/
// Date: 31th May, 2021
// Tags: backtracking, recursion


class Solution {
public:
    
    
    bool exist(vector<vector<char>>& board, string word) {
         int m = board.size();
         int n = board[0].size();
         vector<vector<int>> used;
         used.assign(m, vector<int> (n,0));
         bool flag = false;
         for(int i=0;i<m;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(board[i][j]==word[0] && !flag)
                 {
                     used[i][j]=1;
                     help(i, j, 1, board, word, used, flag);
                     used[i][j]=0;
                 }
             }
         }
        return flag;
    }
    
    static void help(int i, int j, int index, vector<vector<char>>& board,string word,vector<vector<int>> &used, bool &flag)
    {
        if(index<word.size() && !flag)
        {
            int m = board.size();
            int n = board[0].size();
            if(i-1>=0 && used[i-1][j]!=1 && board[i-1][j]==word[index])
            {
                used[i-1][j]=1;
                help(i-1, j, index+1, board, word, used, flag);
                used[i-1][j]=0;
            }
            if(j-1>=0 && used[i][j-1]!=1 && board[i][j-1]==word[index])
            {
                used[i][j-1]=1;
                help(i, j-1, index+1, board, word, used, flag);
                used[i][j-1]=0;
            }
            if(i+1<m && used[i+1][j]!=1 && board[i+1][j]==word[index])
            {
                used[i+1][j]=1;
                help(i+1, j, index+1, board, word, used, flag);
                used[i+1][j]=0;
            }
            if(j+1<n && used[i][j+1]!=1 && board[i][j+1]==word[index])
            {
                used[i][j+1]=1;
                help(i, j+1, index+1, board, word, used, flag);
                used[i][j+1]=0;
            }
        }
        else if(index==word.size())
        {
            flag = true;
        }
    }
};