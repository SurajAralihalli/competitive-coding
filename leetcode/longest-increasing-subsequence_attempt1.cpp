// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/longest-increasing-subsequence/
// Date: 28th May, 2021
// Tags: dp

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        vector <int> vec(n,0);
        if(n>0)
        {
            vec[0]=1;
            maxi =1;
        }
        
        for(int i=1;i<n;i++)
        {
            int local_max=0;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    local_max = max(local_max,vec[j]);
                }
            }
            vec[i] = local_max+1;
            maxi = max(maxi,vec[i]);
        }
        
        return maxi;
    }
};