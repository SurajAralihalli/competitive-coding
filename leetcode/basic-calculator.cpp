// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/basic-calculator/
// Date: 20th July, 2022
// Tags: stack, math



class Solution {
public:
    int calculate(string s) {
        
        
        // 1 -> +
        // -1 -> -
        stack<int> ops;
        stack<int> nums;
        
        int num=0;
        
        //set
        int sign = 1;
        int ans = 0;

        for(char i:s)
        {
            if(isDigit(i))
            {
                num = num*10 + (i - '0');
            }
            else
            {
                //complete number
                ans += sign * num;
                num =0;
                
                if(i==' ')
                {
                    //pass
                }
                else if(i=='(')
                {
                    nums.push(ans);
                    ops.push(sign);
                    
                    //reset
                    sign = 1;
                    ans = 0;
                }
                else if(i==')')
                {
                    // cout << nums.top() << " " << ops.top() << " " << ans << endl;
                    ans = nums.top() + (ops.top() * ans);
                    ops.pop();
                    nums.pop();
                }
                else if(i=='+' || i=='-')
                {
                    sign = i=='+' ? 1 : -1;
                }
            }
        }
        
        //pending one
        ans += sign * num;
        
        return ans;
    }
    
    bool isDigit(char i)
    {
        return (i>='0' && i<='9');
    }
};
