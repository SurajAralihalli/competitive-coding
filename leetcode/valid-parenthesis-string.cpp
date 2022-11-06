// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/valid-parenthesis-string/
// Date: 5th Nov, 2022
// Tags: greedy, string, paranthesis-matching, paranthesis

class Solution {
public:
    bool checkValidString(string s) {
        int leftMin =0;
        int leftMax =0;
        for(char c:s)
        {
            if(c=='(')
            {
                leftMin++;
                leftMax++;
            }
            else if(c==')')
            {
                leftMin--;
                leftMax--;
            }
            else
            {
                //)
                leftMin--;
                //(
                leftMax++;
            }
            
            // leftMax will be less than 0 if ) exceeds ( at any time
            if(leftMax<0) return false;
            if(leftMin<0) leftMin=0;
        }
        
        // min number of ( should be 0
        return leftMin==0;
    }
};
