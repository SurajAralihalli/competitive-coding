// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/remove-duplicate-letters/
// Date: 1st December, 2022
// Tags: stack

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> count;
        set<int> inStack;
        stack<int> stk;
        for(char c: s)
        {
            count[c]++;
        }
        
        for(char c:s)
        {
            count[c]--;
            if(inStack.count(c))
            {
                continue;
            }
            
            while(!stk.empty() && stk.top()>c && count[stk.top()]>0)
            {
                inStack.erase(stk.top());
                stk.pop();
                
            }
            
            stk.push(c);
            inStack.insert(c);
        }
        
        
        string sol;
        while(!stk.empty())
        {
            sol += stk.top();
            stk.pop();
            
        }
        
        reverse(sol.begin(), sol.end());
        
        return sol;
    }
};
