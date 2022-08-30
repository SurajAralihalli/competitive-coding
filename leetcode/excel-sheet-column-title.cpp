// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/excel-sheet-column-title/
// Date: 30th August, 2022
// Tags: math, string

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string sol = "";
        while(columnNumber)
        {
            int x = (columnNumber-1)%26;
            sol = char('A' + x) + sol;
            columnNumber =  (columnNumber-1) /26;
        }
        return sol;
    }
};
