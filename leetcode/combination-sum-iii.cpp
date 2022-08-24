
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/combination-sum-iii/
// Date: 12th June, 2021
// Tags: backtracking

//Approach 2
class Solution {
public:
    vector<vector<int>> mat;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>  vec;
        backtracking(1, 0, n, k, vec);
        return mat;
    }
    
    void backtracking(int index, int sum, int n, int k, vector<int> vec)
    {
        for(int i = index; i<=9; i++)
        {
            if(sum+i==n && vec.size() + 1  == k)
            {
                vector<int> localVec(vec.begin(), vec.end());
                localVec.push_back(i);
                mat.push_back(localVec);
            }
            else if(sum+i <n && vec.size() < k)
            {
                vec.push_back(i);
                backtracking(i+1, sum+i, n, k, vec);
                vec.pop_back();
            }
            else
            {
                break;
            }
        }
    }
};

//Approach 1
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
