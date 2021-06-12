
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/combination-sum-iii/
// Date: 12th June, 2021
// Tags: backtracking


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> mat;
        vector<int> ans;
        help(1, ans, 0, n, k,mat);
        return mat;
    }
    
    static void help(int val, vector<int> ans, int cur_sum, int sum, int k,vector<vector<int>>& mat)
    {
        if(val>9) {return;}
        if(ans.size()>k) {return;}
        if(cur_sum>sum) {return;}
        
        cur_sum = cur_sum+val;
        ans.push_back(val);
        
        if(cur_sum == sum && ans.size()==k){
            mat.push_back(ans);
            return;
        }
        
        help(val+1, ans, cur_sum, sum, k, mat);
        
        ans.pop_back();
        cur_sum = cur_sum - val;
        help(val+1, ans, cur_sum, sum, k, mat);
        
        
        
    }
};
