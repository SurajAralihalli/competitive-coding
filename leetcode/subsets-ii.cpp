// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/subsets-ii/
// Date: 2nd Oct, 2022
// Tags: backtracking, recursion

class Solution {
public:
    vector<vector<int>> sol;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> vec;
        dfs(nums, 0, vec);
        return sol;
    }
    
    void dfs(vector<int>& nums, int index, vector<int> vec)
    {
        sol.push_back(vec);
        int n = nums.size();
        for(int i =index;i<n;i++)
        {
            if(i!=index && nums[i]==nums[i-1])
            {
                continue;
            }
            vec.push_back(nums[i]);
            dfs(nums,i+1,vec);
            vec.pop_back();
        }
    }
};
