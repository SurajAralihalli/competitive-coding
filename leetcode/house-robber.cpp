// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/house-robber/
// Date: 21st June, 2021
// Tags: dp

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        if(n>1) dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        
        return dp[n-1];
    }
};
