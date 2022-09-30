// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Date: 30th September, 2022
// Tags: stack

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next_small_left;
        stack<pair<int,int>> s;
        int n = heights.size();
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && s.top().first >= heights[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                next_small_left.push_back(-1);
            }
            else
            {
                next_small_left.push_back(s.top().second);
            }
            
            s.push({heights[i],i});
        }
        
        vector<int> next_small_right;
        stack<pair<int,int>> s2;
        for(int j=n-1;j>=0;j--)
        {
            while(!s2.empty() && s2.top().first>=heights[j])
            {
                s2.pop();
            }
            if(s2.empty())
            {
                next_small_right.push_back(n);
            }
            else
            {
                next_small_right.push_back(s2.top().second);
            }
            
            s2.push({heights[j],j});
        }
        
        reverse(next_small_right.begin(), next_small_right.end());
        
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi, heights[i]*(next_small_right[i] - next_small_left[i] - 1) );
        }
        
        
        return maxi;
    }
};
