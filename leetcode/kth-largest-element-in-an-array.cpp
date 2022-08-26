// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Date: 26th August, 2022
// Tags: quickselect, quick-select, divide-and-conquer

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0 , nums.size()-1, k);
    }
    
    int quickSelect(vector<int>& nums, int l, int h, int k)
    {
        int pointer = l-1;
        for(int i=l; i<h; i++)
        {
            if(nums[i]<nums[h])
            {
                pointer++;
                swap(nums[pointer], nums[i]);
            }
            else
            {
                //do nothing
            }
        }
        pointer++;
        swap(nums[pointer], nums[h]);
    
        int v = h - pointer + 1;
        // nums[pointer] is vth highest
                
        if(v==k) return nums[pointer];
        else if(v>k)
        {
            return quickSelect(nums, pointer+1 , h, k);
        }
        else
        {
            return quickSelect(nums, l , pointer-1, k-v);
        }
    
    }
};
