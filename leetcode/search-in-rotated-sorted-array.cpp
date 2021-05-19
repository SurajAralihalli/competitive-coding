// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Date: 19th May, 2021
// Tags: binary-search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r = nums.size()-1;
        int mid;
        bool found = false;
        int result = target;
        while(l<r)
        {
            mid = (l+r)/2;
            int a = nums[l];
            int b = nums[mid];
            int c = nums[r];
            
            if(b==result)
            {
                return mid;
            }
            
            if(a<=b)
            {
                if(result <b && result >=a)
                {
                    r = mid-1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if(result <= c && result >b)
                {
                    l = mid+1;
                }
                else
                {
                    r = mid -1;
                }
            }
        }
        if(l==r && result==nums[l])
        {
            return l;
        }
        else
        {
            return -1;
        }
    }
};