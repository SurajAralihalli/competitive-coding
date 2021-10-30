// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/merge-intervals/
// Date: 30th October, 2021
// Tags: greedy, interval-scheduling

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),comp);
        for(auto vec: intervals)
        {
            if(!ans.empty())
            {
                auto l = ans.back();
                //compatible
                if(l[1]>= vec[0])
                {
                    ans.pop_back();
                    vector<int> temp;
                    temp.push_back(l[0]);
                    temp.push_back(max(l[1],vec[1]));
                    ans.push_back(temp);
                }
                //non compatibe
                else
                {
                    ans.push_back(vec);
                }
            }
            else
            {
                ans.push_back(vec);
            }
        }
        return ans;
        
        
    }
    static bool comp(vector<int> a,  vector<int> b)
    {
        return a[0]<b[0];
    }
};
