// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/merge-intervals/
// Date: 30th October, 2021
// Tags: greedy, interval-scheduling, intervals

// Approach 1
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


// Approach 2
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue< pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>> > pq;
        vector<vector<int>> sol;
        for(auto i: intervals)
        {
            pq.push({i[0], i});
        }
        
        sol.push_back(pq.top().second);
        pq.pop();
        
        while(!pq.empty())
        {
            auto t = pq.top();
            auto l = sol.back();
            
            //compatible
            if(t.first<= l[1])
            {
                sol.pop_back();
                sol.push_back({l[0], max(l[1],t.second[1])});
            }
            else
            {
                sol.push_back(t.second);
            }
            
            pq.pop();
        }
        
        return sol;
    }
};
