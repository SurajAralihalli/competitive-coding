// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/longest-common-subsequence/
// Date: 11th November, 2021
// Tags: dp, subsequence

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.size();
        int b = text2.size();
        vector<vector<int>> dp;
        dp.assign(a+1, vector<int>(b+1,0));
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    // dp[i][j] = max(1+dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[a][b];
    }
};
