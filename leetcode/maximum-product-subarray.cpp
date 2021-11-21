// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/maximum-product-subarray/
// Date: 12th May, 2021
// Tags: dp, arrays

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_until_now = nums[0];
        int min_until_now = nums[0];
        int global_max = nums[0];
        
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            // cout << max_until_now << " " << min_until_now << " "<< global_max << endl;
            int new_max = max({nums[i], nums[i]*max_until_now, nums[i]*min_until_now});
            int new_min = min({nums[i], nums[i]*max_until_now, nums[i]*min_until_now});
            
            max_until_now = new_max;
            min_until_now = new_min;
            
            global_max = max(global_max, max_until_now);
        }
        
        return global_max;
    }
};
