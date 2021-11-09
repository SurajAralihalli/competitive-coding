// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/greatest-sum-divisible-by-three/
// Date: 9th November, 2021
// Tags: dp

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp;
        int n = nums.size();
        dp.assign(n+1,vector<int>(3,0));
        dp[0][1] = INT_MIN;
        dp[0][2] = INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(nums[i-1]%3==0)
            {
                dp[i][0] = max(dp[i-1][0],dp[i-1][0] + nums[i-1]);
                dp[i][1] = max(dp[i-1][1],dp[i-1][1] + nums[i-1]);
                dp[i][2] = max(dp[i-1][2],dp[i-1][2] + nums[i-1]);
            }
            else if(nums[i-1]%3==1)
            {
                dp[i][0] = max(dp[i-1][0],dp[i-1][2] + nums[i-1]);
                dp[i][1] = max(dp[i-1][1],dp[i-1][0] + nums[i-1]);
                dp[i][2] = max(dp[i-1][2],dp[i-1][1] + nums[i-1]);
            }
            else if(nums[i-1]%3==2)
            {
                dp[i][0] = max(dp[i-1][0],dp[i-1][1] + nums[i-1]);
                dp[i][1] = max(dp[i-1][1],dp[i-1][2] + nums[i-1]);
                dp[i][2] = max(dp[i-1][2],dp[i-1][0] + nums[i-1]);
            }
        }
        for(auto i: dp)
        {
            for(auto j:i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        return dp[n][0];
    }
};
