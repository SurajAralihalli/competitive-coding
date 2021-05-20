// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/jump-game/
// Date: 20th May, 2021

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> vec(nums.size(),0);
        for(int i=0;i<nums.size()-1;i++)
        {
            int h = vec[i];
            if(i!=0 && h==0) break;
            for(int j=1;j<=nums[i];j++)
            {
                if((i+j) < nums.size() && vec[i+j]==0)
                {
                vec[i+j] = (h + 1);
                }
            }
        }
        // for(int i=0;i<nums.size();i++)
        // {
        //     cout << vec[i] << " ";
        // }
        if(vec[nums.size()-1] || nums.size()==1)
        {
            return true;
        }
        return false;
    }
};