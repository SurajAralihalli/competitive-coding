
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/longest-consecutive-sequence/
// Date: 7th June, 2021
// Tags: map, union-find, sequence


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> map;
        for(int i: nums)
        {
            map[i]=true;
        }
        int maxi=0;
        while(!map.empty())
        {
            
            int n = map.begin()->first;
            map.erase(n);
            int local_maxi = 1;
            
            int f = n+1;
            while(map.find(f)!=map.end())
            {
                local_maxi++;
                map.erase(f);
                f++;
            }
            
            int b = n-1;
            while(map.find(b)!=map.end())
            {
                local_maxi++;
                map.erase(b);
                b--;
            }
            
            maxi= max(local_maxi,maxi);
            
            
        }
        
        return maxi;
    }
};
