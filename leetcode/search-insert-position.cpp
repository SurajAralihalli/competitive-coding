// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/search-insert-position/
// Date: 26th June, 2022
// Tags: binary-search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l =0;
        int r =n-1;
        
        while(l<=r)
        {
            int m = (l+r)/2;
            
            if(nums[m]==target) return m;
            //two elements
            else if(l==r-1)
            {
                if(nums[l]>target) return l;
                else if(nums[r]>target) return r;
                else if(nums[r]<target) return r+1;
            }
            else if(l==r)
            {
                return nums[l]>target?l:l+1;
            }
            
            
            if(nums[m]>target) 
            {
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }
        
        return -1;
    }
};
