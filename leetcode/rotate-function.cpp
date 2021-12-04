// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/rotate-function/
// Date: 4th December, 2021
// Tags: dp



class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        int transformed_sum = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++)
        {
            total_sum += nums[i];
            transformed_sum += (i * nums[i]);
        }
        maxi = max(maxi, transformed_sum);
        
        for(int i=0;i<n;i++)
        {
            
            transformed_sum = transformed_sum - total_sum + (n * nums[i]);
            maxi = max(maxi, transformed_sum);
        }
        
        return maxi;
    }
};
