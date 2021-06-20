// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/coin-change/
// Date: 20th May, 2021
// Tags: dp


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        dp.assign(amount+1,0);
        return help(coins, amount,dp)==INT_MAX?-1:dp[amount];
    }
    
    int help(vector<int>& coins, int amount,vector<int>& dp)
    {
        // cout << amount << " " << n << endl;
        if(amount==0){return 0;}
        if(amount<0) {return -1;}
        int s = coins.size();
        int mini=INT_MAX;
        if(dp[amount]==0)
        {
            
            for(int i=0;i<s;i++)
            {
               if(amount>=coins[i])
               {
                   // cout << amount<< " " << coins[i] << " " << n << endl;
                   int res = help(coins, amount-coins[i],dp);
                   if(res!=-1)
                   {
                    mini = min(res+1,mini);
                   }
                   
               }
            }
            
            
            dp[amount] = mini==INT_MAX?-1:mini;
        }
        // cout << "return " << amount << " coins " <<  dp[amount] << endl;
        return dp[amount];
        
    }
};
