// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Date: 25th September, 2022
// Tags: stack


class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        return (int)evalRPNHelp(tokens);
    }
    
    long evalRPNHelp(vector<string>& tokens) {
        if(tokens.size()!=0)
        {
            string s = tokens.back();
            tokens.pop_back();
            
            if(s=="-" || s=="*" || s=="/" || s=="+" )
            {
                long r = evalRPN(tokens);
                long l = evalRPN(tokens);
                
                if(s=="-") return l - r;
                else if(s=="+") return l + r;
                else if(s=="*") return l * r;
                else if(s=="/") return l / r;
                else return -1;
                
            }
            else
            {
                return stoi(s);
            }
            
        }
        return -1;
    }
};
