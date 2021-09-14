// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/coin-change-2/
// Date: 20th June, 2021
// Tags: dp


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector< vector<int> > dp;
        int n = coins.size();
        dp.assign(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(j>=coins[i-1])
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                    
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][amount];
    }
};
