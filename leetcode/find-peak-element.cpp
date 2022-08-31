// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/find-peak-element/
// Date: 30th August, 2022
// Tags: binary-search

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        while(l<=r)
        {
            int m = l + (r-l)/2;
            if(l==r) 
            {
                return l;
            }
            if(r==l+1)
            {
                return nums[l]>nums[r]?l:r;
            }
            else
            {
                if(nums[m-1] < nums[m] && nums[m]> nums[m+1]) 
                {
                    return m;
                }
                else if(nums[m-1] > nums[m])
                {
                    r = m-1;
                }
                else
                {
                    l = m+1;
                }
            }
        }
        
        return -1;
    }
};
