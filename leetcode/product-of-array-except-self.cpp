
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/product-of-array-except-self/description/
// Date: 4th April, 2023
// Tags: array, prefix-sum

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec(n,0);
        int countZeroes = 0;
        int prod =1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                countZeroes++;
            }
            else
            {
                prod*= nums[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0 && countZeroes>1)
            {
                vec[i] = 0;
            }
            else if(nums[i]==0)
            {
                vec[i] = prod;
            }
            else if(countZeroes>0)
            {
                vec[i] = 0;
            }
            else
            {
                vec[i] = prod / nums[i];
            }
        }
        
        return vec;
    }
};
