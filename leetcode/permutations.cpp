// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/permutations/
// Date: 23rd June, 2021
// Tags: backtracking

//Approach 1
class Solution {
public:
    vector<vector<int>> sol;
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, bool> used;
        for(int i: nums)
        {
            used[i] = false;
        }
        vector<int> vec;
        dfs(nums,used,vec);
        return sol;
    }
    void dfs(vector<int>& nums, unordered_map<int, bool>& used, vector<int> vec)
    {
        int n = nums.size();
        if(vec.size()==n)
        {
           sol.push_back(vec);
           return;
        }
        
        for(int i: nums)
        {
            if(used[i]==false)
            {
                used[i]=true;
                vec.push_back(i);
                dfs(nums,used,vec);
                vec.pop_back();
                used[i]=false;
            }
        }
    }
};

//Approach 2
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> mat;
        unordered_map<int,bool> map;
        for(int i:nums)
        {
            map[i]=false;
        }
        vector<int> vec;
        help(nums,map,mat,vec);
        return mat;
    }
    
    void help(vector<int>& nums,unordered_map<int,bool>& map,vector<vector<int>>& mat, vector<int> vec)
    {
        for(int i: nums)
        {
            if(map[i]==false)
            {
                vec.push_back(i);
                if(vec.size() == nums.size())
                {
                    mat.push_back(vec);
                    break;
                }
                map[i]=true;
                help(nums,map,mat,vec);
                vec.pop_back();
                map[i]=false;
            }
        }
    }
};
