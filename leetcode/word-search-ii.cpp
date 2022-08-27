// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/word-search-ii/
// Date: 27th August, 2022
// Tags: trie, backtracking, dfs


//Approach 2
class Solution {
public:
    vector<vector<char>> mat;
    int n;
    int m;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size();
        m = board[0].size();
        mat = board;
        vector<vector<int>> marked(n, vector<int>(m, 0));
        vector<string> wordsFound;
        for(auto word: words)
        {
            bool wordFound = false;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(board[i][j]==word[0])
                    {
                        marked[i][j]=1;
                        wordFound = findWord(marked, word, 1, i, j);
                        marked[i][j]=0;
                    }
                    
                    if(wordFound) 
                    {
                        wordsFound.push_back(word);
                        break;
                    }
                }
                if(wordFound) break;
            }   
        }
        
        return wordsFound;
        
    }
    
    bool findWord(vector<vector<int>>& marked, string word, int index, int x, int y)
    {
        int l = word.size();
        if(index==l) return true;
        else
        {
            bool wordFound = false;
            if(!wordFound && x+1<n && marked[x+1][y]==0 &&  mat[x+1][y]==word[index])
            {
                
                marked[x+1][y]=1;
                wordFound = findWord(marked, word, index+1, x+1, y);
                marked[x+1][y]=0;
            }
            if(!wordFound && x-1>=0 && marked[x-1][y]==0 && mat[x-1][y]==word[index])
            {
                marked[x-1][y]=1;
                wordFound = findWord(marked, word, index+1, x-1, y);
                marked[x-1][y]=0;
            }
            if(!wordFound && y+1<m && marked[x][y+1]==0 && mat[x][y+1]==word[index])
            {
                marked[x][y+1]=1;
                wordFound = findWord(marked, word, index+1, x, y+1);
                marked[x][y+1]=0;
            }
            if(!wordFound && y-1>=0 && marked[x][y-1]==0 && mat[x][y-1]==word[index])
            {
                marked[x][y-1]=1;
                wordFound = findWord(marked, word, index+1, x, y-1);
                marked[x][y-1]=0;
                
            }
            
            return wordFound;
            
        }
    }
    
    
};
