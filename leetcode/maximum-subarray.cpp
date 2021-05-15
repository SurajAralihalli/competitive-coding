// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/maximum-subarray/
// Date: 12th May, 2021

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            maxi = max(nums[i],maxi);
            sum += nums[i];
            maxi = max(sum,maxi);
            if( sum<0)
            {
                sum=0;
            }
            // maxi = max(sum,maxi);
        }
        return maxi;
    }
};