// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/decode-string/
// Date: 7th Nov, 2022
// Tags: stack, string

class Solution {
public:
    string decodeString(string s) {
        stack<string> strStack;
        stack<int> countStack;
        
        int k=0;
        string curString=""; 
        for(char c: s)
        {
            
            if(c=='[')
            {
                strStack.push(curString);
                countStack.push(k);
                
                //reset
                k=0;
                curString="";
            }
            // start decoding
            else if(c==']')
            {
                int count = countStack.top();
                countStack.pop();
                
                string prevString = strStack.top();
                strStack.pop();
                
                string generatedString = "";
                for(int i=0;i<count;i++)
                {
                    generatedString+=curString;
                }
                
                curString = prevString + generatedString;
            }
            else if(c-'0' >= 0 and c-'0' <=9)
            {
                k=k*10 + (c-'0');
            }
            else
            {
                curString += string(1, c);   
            }
        }
        
        return curString;
    }
    
    
};
