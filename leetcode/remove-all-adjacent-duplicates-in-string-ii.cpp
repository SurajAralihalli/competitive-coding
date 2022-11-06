// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
// Date: 6th Nov, 2022
// Tags: stack, string

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> myStack;
        for(char c:s)
        {
            if(!myStack.empty())
            {
                auto top = myStack.top();
                
                if(top.first==c)
                {
                    myStack.pop();
                    
                    // update count
                    top.second+=1;
                    myStack.push(top);
                    
                    if(top.second==k)
                    {
                        myStack.pop();
                    }
                }
                else
                {
                    myStack.push({c,1});
                }
            }
            else
            {
                myStack.push({c,1});
            }
        }
        
        string result = "";
        while(!myStack.empty())
        {
            auto top = myStack.top();
            myStack.pop();
            
            result += string(top.second, top.first);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
