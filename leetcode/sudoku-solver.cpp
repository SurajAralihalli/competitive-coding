// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/sudoku-solver/
// Date: 13th Nov, 2022
// Tags: backtracking

class Solution {
public:
    vector<unordered_set<int>> rowSet;
    vector<unordered_set<int>> columnSet;
    vector<vector<unordered_set<int>>> boxSet;
    bool isSolvable;
    void solveSudoku(vector<vector<char>>& board) {
        rowSet.assign(9, unordered_set<int>());
        columnSet.assign(9, unordered_set<int>());
        boxSet.assign(3, vector<unordered_set<int>>(3, unordered_set<int>()));
        
        buildSets(board);
        isSolvable = false;
        
        dfs(board, 0, 0);

    }
    
    void dfs(vector<vector<char>>& board, int r,int c)
    {
        if(r==9)
        {
            isSolvable = true;
        }
        else if(board[r][c]=='.')
        {
            int nr = c==8?r+1:r;
            int nc = c==8?0:c+1;
            
            for(int v=1;v<=9;v++)
            {
                if(rowSet[r].count(v) + columnSet[c].count(v)+boxSet[r/3][c/3].count(v) == 0)
                {
                    board[r][c] = v + '0';
                    
                    rowSet[r].insert(v);
                    columnSet[c].insert(v);
                    boxSet[r/3][c/3].insert(v);
                    
                    dfs(board, nr, nc);
                    
                    if(isSolvable) return;
                    
                    rowSet[r].erase(v);
                    columnSet[c].erase(v);
                    boxSet[r/3][c/3].erase(v);
                    
                    
                    board[r][c] = '.';
                }
            }
        }
        else
        {
            int nr = c==9?r+1:r;
            int nc = c==9?0:c+1;
            
            dfs(board, nr, nc);
        }    
    }
    
    void buildSets(vector<vector<char>>& board)
    {
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                if(board[r][c]!='.')
                {
                    int v = board[r][c]-'0';
                    
                    rowSet[r].insert(v);
                    columnSet[c].insert(v);
                    boxSet[r/3][c/3].insert(v);
                }
            }
        }
    }
    
    
};
