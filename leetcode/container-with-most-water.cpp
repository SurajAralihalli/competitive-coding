// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/container-with-most-water/
// Date: 15th May, 2021
// Tags: two pointers

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l =0;
        int r = n-1;
        int maxi = 0;
        while(l<r)
        {
            int v = min(height[l],height[r]) * (r-l);
            
            if(height[l]>height[r])
            {
                r=r-1;
            }
            else
            {
                l = l +1;
            }
            maxi = max(v,maxi);
            
        }
        return maxi;
    }
};