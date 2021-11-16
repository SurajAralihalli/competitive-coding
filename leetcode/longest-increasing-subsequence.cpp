// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/longest-increasing-subsequence/
// Date: 15th Novembeer, 2021
// Tags: dp

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n+1,0);
            int globalM = 0;
            for(int i=0;i<n;i++)
            {
                int maxi=0;
                for(int j=0;j<i;j++)
                {
                    if(nums[j]<nums[i])
                    {
                        maxi = max(dp[j],maxi);
                    }
                }
                dp[i]=maxi+1;
                globalM = max(dp[i],globalM);
            }
        
        return globalM;
    }
    
    
};
