// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/permutations/
// Date: 13th Nov, 2021
// Tags: backtracking

class Solution {
public:
    vector<vector<int>> sol;
    unordered_set<int> used;
    
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> vec;
        dfs(nums,vec);
        return sol;
    }
    
    void dfs(vector<int>& nums, vector<int> vec)
    {
        int n = nums.size();
        if(vec.size()==n)
        {
           sol.push_back(vec);
           return;
        }
        
        for(int i: nums)
        {
            if(used.count(i) == 0)
            {
                used.insert(i);
                vec.push_back(i);
                
                dfs(nums,vec);
                
                vec.pop_back();
                used.erase(i);
            }
        }
    }
};
