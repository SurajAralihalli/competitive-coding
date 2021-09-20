// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/subarray-sum-equals-k/
// Date: 20th September, 2021
// Tags: sliding-window

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count=0;
        int csum =0;
        unordered_map<int,int> map;
        map[0]=1;
        for(int i=0;i<n;i++)
        {
            csum+= nums[i];
            if(map.find(csum-k)!=map.end())
            {
                count+=map[csum-k];
            }
            
            map[csum]=map.find(csum)==map.end()?1:map[csum]+1;
        }
        // for(auto i:map)
        // {
        //     cout << i.first << " " << i.second << endl;
        // }
        return count;
    }
};
