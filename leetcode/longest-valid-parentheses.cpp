// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/longest-valid-parentheses/
// Date: 13th May, 2021

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxi = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                if(stk.empty())
                {
                    stk.push(i);
                }
                int l = i - stk.top();
                maxi = max(maxi,l);
            }
        }
        return maxi;
    }
};