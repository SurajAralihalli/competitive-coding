// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/maximum-product-subarray/
// Date: 12th May, 2021


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod;
        for(int i=0;i<nums.size();i++)
        {
            prod =1;
            for (int j=i;j<nums.size();j++)
            {
                prod *= nums[j];
                maxi=max(maxi,prod);
                // cout << maxi << endl;
            }
        }
        return maxi;
        
    }
};