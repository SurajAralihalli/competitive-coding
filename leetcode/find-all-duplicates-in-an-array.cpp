
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/find-all-duplicates-in-an-array/
// Date: 23rd June, 2021
// Tags: array


class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int value = nums[i]>0 ? nums[i]:(nums[i]*-1);
            int correct_index = value-1;
            if(nums[correct_index]<0)
            {
                ans.push_back(value);
            }
            else
            {
                nums[correct_index] = (nums[correct_index]*-1);
            }
        }
        
        return ans;
    }
    
    
};
