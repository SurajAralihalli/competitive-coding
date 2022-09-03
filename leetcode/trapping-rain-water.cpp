// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/trapping-rain-water/
// Date: 3rd Sept, 2022
// Tags: dp, two-pointers

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        
        vector<int> leftMax(n,0);
        int leftM =0;
        for(int i=0;i<n;i++)
        {
            if(leftM>=height[i])
            {
                leftMax[i] = leftM;
            }
            leftM = max(leftM, height[i]);
        }
        
        vector<int> rightMax(n,0);
        int rightM = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(rightM>=height[i])
            {
                rightMax[i] = rightM;
            }
            rightM = max(rightM, height[i]);
        }
        
        int trappedWater = 0;
        for(int i=0;i<n;i++)
        {
            int lmax = leftMax[i];
            int rmax = rightMax[i];
            if(lmax!=0 && rmax!=0)
            {
                trappedWater += min(lmax, rmax) - height[i];
            }
        }
        
        return trappedWater;
    }
};
