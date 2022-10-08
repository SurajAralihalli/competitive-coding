// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/valid-sudoku/
// Date: 8th Oct, 2022
// Tags: array, hashing

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rowSet(9);
        vector<unordered_set<int>> columnSet(9);
        vector<vector<unordered_set<int>>> boxSet(3, vector<unordered_set<int>>(3));
        
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                if(board[r][c]=='.') continue;
                
                int number = board[r][c] - '0';
                
                //check rowSet
                if(rowSet[r].find(number)!=rowSet[r].end())
                {
                    return false;
                }
                else
                {
                    rowSet[r].insert(number);
                }
                //check columnSet
                if(columnSet[c].find(number)!=columnSet[c].end())
                {
                    return false;
                }
                else
                {
                    columnSet[c].insert(number);
                }
                //boxSet
                if(boxSet[r/3][c/3].find(number)!=boxSet[r/3][c/3].end())
                {
                    return false;
                }
                else
                {
                    boxSet[r/3][c/3].insert(number);
                }
                
            }
        }
        
        
        return true;
    }
};
