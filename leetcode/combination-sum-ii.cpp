// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/combination-sum-ii/
// Date: 2nd Oct, 2022
// Tags: backtracking, recursion

class Solution {
public:
    vector<vector<int>> sol;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, tmp, 0);
        return sol;
    }
    
    void dfs(vector<int>& candidates, int target,vector<int> tmp, int index)
    {
        if(target==0)
        {
            sol.push_back(tmp);
            return;
        }
        if(target<0)
        {
            return;
        }
        
        for(int i=index;i<candidates.size();i++)
        {
            if(i!=index && candidates[i]==candidates[i-1])
            {
                continue;
            }
            tmp.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], tmp, i+1);
            tmp.pop_back();
        }
    }
};
