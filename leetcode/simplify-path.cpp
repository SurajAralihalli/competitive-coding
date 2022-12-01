// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/simplify-path/
// Date: 30th Nov, 2022
// Tags: stack, string

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        stack<string> stk;
        string token;
        string ans;
        while(getline(ss,token,'/'))
        {
            if(token=="." || token=="")
            {
                continue;
            }
            else if(token=="..")
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
            }
            else
            {
                stk.push(token);
            }
        }
        
        while(!stk.empty())
        {
            if(ans!="")
            {
                ans = stk.top() + "/" + ans;
            }
            else
            {
                ans = stk.top();
            }
            stk.pop();
        }
        
        
        return "/" + ans;
    }
};
