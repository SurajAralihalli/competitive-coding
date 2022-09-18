// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/sliding-window-maximum/
// Date: 18th September, 2022
// Tags: fixed-sliding-window

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        list<int> maxNums;
        vector<int> sol;
        int i=0;
        int j=0;
        while(j<n)
        {
            int w = j-i+1;
            while(!maxNums.empty() && maxNums.back()<nums[j])
            {
                maxNums.pop_back();
            }
            maxNums.push_back(nums[j]);
            if(w<k)
            {
                j++;
            }
            else
            {
                sol.push_back(maxNums.front());
                if(maxNums.front() == nums[i])
                {
                    maxNums.pop_front();
                }
                i++;
                j++;
            }
        }
        return sol;
    }
};
