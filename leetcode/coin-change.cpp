// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/coin-change/
// Date: 20th June, 2021
// Tags: dp

//Approach 1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount +1, 0));
        
        for(int j=0;j<=amount;j++) 
        {
            dp[0][j] = INT_MAX;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(j>=coins[i-1])
                {
                    
                    int plusOne = dp[i][j-coins[i-1]] == INT_MAX? INT_MAX : dp[i][j-coins[i-1]] +1;
                    
                    dp[i][j] = min(dp[i-1][j], plusOne);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][amount] == INT_MAX? -1: dp[n][amount];
    }
};

//Approach 2
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
