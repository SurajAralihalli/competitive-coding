// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/basic-calculator-ii/
// Date: 21st July, 2022
// Tags: stack, math

class Solution {
public:
    int calculate(string s) {
        stack<int> partialAns;
        
        //set
        int num=0;
        int sign =1;
        // 1 -> + 
        //-1 -> -
        int processMutDiv = 0;
        // 0 -> not processing
        // 1 -> mul
        // 2 -> div
        
        s = s + "+0";
        for(char c:s)
        {
            if(isDigit(c))
            {
                num = num*10 + (c -'0');
            }
            else if(c!=' ')
            {
                // cout << num << endl;
                if(processMutDiv)
                {
                    int top = partialAns.top();
                    partialAns.pop();
                    int ans = processMutDiv == 1 ? (top * (sign * num)) : (top / (sign * num));
                    partialAns.push(ans);
                    
                    //reset
                    num=0;
                    sign =1;
                    processMutDiv = 0;
                    
                }
                else
                {
                    partialAns.push(sign * num);
                    //reset
                    num=0;
                    sign =1;    
                }
                
                if(c == '+' || c == '-')
                {
                    sign = (c == '+')? 1 : -1;

                }
                else if(c == '*' || c =='/')
                {
                    processMutDiv = (c == '*')? 1 : 2;
                }
                
            }
        }
        
        int finalAns =0;
        while(!partialAns.empty())
        {
            finalAns+=partialAns.top();
            partialAns.pop();
        }
        return finalAns;
    }
    
    bool isDigit(char c)
    {
        return c>='0' && c<='9';
    }
};
