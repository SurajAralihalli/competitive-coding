// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/subarrays-with-k-different-integers/
// Date: 7th November, 2021
// Tags: variable-sliding-window


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int x = atmostk(nums,k) - atmostk(nums,k-1);
        return x<0?0:x;
    }
    
    
    int atmostk(vector<int> nums, int k)
    {
        nums.push_back(INT_MAX);
        int n = nums.size();
        int i = 0;
        int j= 0;
        unordered_map<int,int> map;
        int c = 0;
        int sub =0;
        while(j<n)
        {
            // cout << i << " " << j << endl;
            if(map.find(nums[j])!=map.end())
            {
                map[nums[j]]++;
            }
            else
            {
                map[nums[j]]=1;
            }
            int w = (j-i+1);
            if(map.size()<=k)
            {
                j++;
            }
            else
            {
                while(map.size()>k || (j==(n-1) && i<=j) )
                { 
                    
                    // cout << i << endl;
                    sub = sub + (j-i);
                    // cout << i << " " << j << " " << (j-i) << endl;
                    
                    map[nums[i]]--;
                    if(map[nums[i]]==0)
                    {
                        map.erase(map.find(nums[i]));
                    }
                    i++;
                }
                j++;
            }
            
        }
        
        return sub;
    }
};



