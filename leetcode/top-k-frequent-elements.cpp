// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/top-k-frequent-elements/
// Date: 8th Oct, 2022
// Tags: array, hashing

//O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(auto i: nums)
        {
            map[i]++;
        }
        int n = nums.size();
        // count : {nums[i]}
        vector<vector<int>> buckets(n+1);
        for(auto i:map)
        {
            buckets[i.second].push_back(i.first);
        }
        
        vector<int> sol;
        for(int i=n; i>=0;i--)
        {
            if(!buckets[i].empty())
            {
                for(auto j: buckets[i])
                {
                    if(sol.size()<k)
                    {
                        sol.push_back(j);
                    }
                    else
                    {
                        return sol;
                    }
                }
            }
        }
        
        return sol;
    }
};
