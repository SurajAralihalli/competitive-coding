// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/house-robber-ii/
// Date: 22nd November, 2021
// Tags: dp

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        vector<int> dp;
        int maxi =0;
        dp.assign(n,0);
        dp[0] = nums[0];
        maxi = max(dp[0],maxi);
        if(n>1) 
        {
            dp[1] = max(dp[0],nums[1]);
            maxi = max(dp[1],maxi);
                
        }; 
        for(int i=2;i<n-1;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        maxi = max(dp[n-2],maxi);
        
        reverse(nums.begin(),nums.end());
        dp.assign(n,0);
        dp[0] = nums[0];
        maxi = max(dp[0],maxi);
        if(n>1) 
        {
            dp[1] = max(dp[0],nums[1]);
            maxi = max(dp[1],maxi);
                
        };
        for(int i=2;i<n-1;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        maxi = max(dp[n-2],maxi);
        
        return maxi;
        
    }
};
