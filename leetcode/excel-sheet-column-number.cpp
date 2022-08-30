// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/excel-sheet-column-number/
// Date: 30th August, 2022
// Tags: math, string


class Solution {
public:
    int titleToNumber(string columnTitle) {
        reverse(columnTitle.begin(), columnTitle.end());
        int n =0;
        long i = 1;
        for(char c: columnTitle)
        {
            int v = c -'A' + 1;
            n += v * i;
            i*=26;
        }
        
        return n;
    }
};
