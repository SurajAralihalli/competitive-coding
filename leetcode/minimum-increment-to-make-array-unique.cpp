// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/minimum-increment-to-make-array-unique/
// Date: 13th Nov, 2021
// Tags: greedy

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev = -1;
        int count = 0;
        for(auto i: nums)
        {
            if(prev>=i)
            {
                int n = prev+1;
                count+= (n-i);
                prev = n;
            }
            else
            {
                prev =i;
            } 
        }
        return count;
    }
};
