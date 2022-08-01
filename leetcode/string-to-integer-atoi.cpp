// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/string-to-integer-atoi/
// Date: 31st July, 2022
// Tags: string, integer


class Solution {
public:
    int myAtoi(string s) {
        // remove whitespace
        int w=0;
        while(w< s.size() && s[w]==' ')
        {
            w++;
        }
        s = (w==0) ? s : s.substr(w);         
        
        int sign = 1;
        //check sign
        if(s[0] == '-')
        {
            sign = -1;
            s = s.substr(1);
        }
        else if(s[0] == '+')
        {
            s = s.substr(1);
        }
        
        long long val=0;
        int i = 0;
        while(i < s.size() && s[i] >= '0' && s[i] <= '9')
        {
            if(val * sign > INT_MAX)
            {
                return INT_MAX;
            }
            else if(val * sign < INT_MIN)
            {
                return INT_MIN;
            }
            
            val = 10 * val + (long long)(s[i] - '0');
            i++;
        }
        
        val = val * sign;
         if(val > INT_MAX)
        {
            return INT_MAX;
        }
        else if(val < INT_MIN)
        {
            return INT_MIN;
        }
        return (int)val;
    }
};
