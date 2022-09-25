// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/generate-parentheses/
// Date: 25th September, 2022
// Tags: backtracking

class Solution {
public:
    vector<string> sol;
    vector<string> generateParenthesis(int n) {
        recursive(0,0,n, "");
        return sol;
    }
    
    void recursive(int open, int close, int n, string s)
    {
        if(open<n)
        {
            recursive(open+1,close,n,s+"(");
        }
        
        if(close<open)
        {
            recursive(open,close+1,n,s+")");
        }
        
        if(open == n && close == n)
        {
            sol.push_back(s);
        }
    }
};
