// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/jump-game-ii/
// Date: 20th May, 2021

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> vec(nums.size(),0);
        int n = nums.size();
        for(int j=1;j<n;j++)
        {
            int i=0;
            while(i<j)
            {
                int a = nums[i];
                if(i+a >= j)
                {
                    vec[j] = vec[i]+1;
                    break;
                }
                i++;
            }
        }
        // for(int i=0;i<nums.size();i++)
        // {
        //     cout << vec[i] << " ";
        // }
        // if(vec[nums.size()-1] || nums.size()==1)
        // {
        //     return true;
        // }
        // return false;
        return vec[n-1];
    }
};