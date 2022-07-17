// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/non-overlapping-intervals/
// Date: 17th July, 2022
// Tags: arrays, intervals

// find max number of non overlapping intervals - sort based on end times
// This is because, the interval with the earliest end time produces the maximal capacity to hold rest intervals.
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), sortAsc);
        
        int overlap = 0;
        auto prev = intervals[0]; 
        for(int i = 1; i<n; i++)
        {
            //check overlap
            if(intervals[i][0] < prev[1])
            {
                overlap++;
            }
            else
            {
                prev = intervals[i];
            }
        }
        
        return overlap;
    }
    
    static bool sortAsc(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }
};
