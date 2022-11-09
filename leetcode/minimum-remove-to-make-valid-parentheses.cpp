// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// Date: 8th Nov, 2022
// Tags: strings, stack, stacks

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> leftOpen;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                leftOpen.push(i);
            }
            else if(s[i]==')')
            {
                if(leftOpen.empty())
                {
                    //extra ')' 
                    s[i] = '$';
                }
                else
                {
                    leftOpen.pop();
                }
            }
        }
        string sol = "";
        for(int i=n-1;i>=0;i--)
        {
            // extra '('
            if(!leftOpen.empty() && leftOpen.top()==i)
            {
                leftOpen.pop();
            }
            else if(s[i]!='$')
            {
                sol.push_back(s[i]);
            }
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
