
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/non-overlapping-intervals/
// Date: 6th December, 2021
// Tags: arrays, intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> bag;
        int noncomp = 0;
        for(auto i: intervals)
        {
            if(!bag.empty())
            {
                auto l = bag.back();
                //no overlap
                if(l[1]<=i[0])
                {
                    bag.push_back(i);
                    
                }
                //overlap
                else
                {
                    if(l[1]>i[1])
                    {
                        bag.pop_back();
                        bag.push_back(i);
                    }
                    noncomp++;
                }
            }
            else
            {
                bag.push_back(i);
            }
        }
        return noncomp;
    }
    
    static bool comp(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }
};
