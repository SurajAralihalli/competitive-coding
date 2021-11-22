// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/counting-bits/
// Date: 22nd November, 2021
// Tags: dp, bitwise

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        if(n==0) return dp;
        dp[0]=0;
        dp[1]=1;
        int digit =2;
        for(int i=2;i<=n;i++)
        {
            if(i == digit*2)
            {
                digit = digit*2;
            }
            dp[i] = dp[i-digit]+1;
        }
        
        return dp;
        
    }
};
