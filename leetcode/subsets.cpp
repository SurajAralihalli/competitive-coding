// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/subsets/
// Date: 29th June, 2022
// Tags: backtracking, recursion


// Approach 2
class Solution {
public:
    vector<vector<int>> sol;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        dfs(nums,0,vec);
        return sol;
    }
    
    void dfs(vector<int>& nums, int index, vector<int> vec)
    {
        int n = nums.size();
        sol.push_back(vec);
        
        for(int i=index;i<n;i++)
        {
            vec.push_back(nums[i]);
            dfs(nums,i+1,vec);
            vec.pop_back();
        }
    }
};




// Approach 1
class Solution {
public:
    vector<vector<int>> mat;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        vec.clear();
        generateSubsets(nums,vec,0);
        return mat;
        
    }
    
    void generateSubsets(vector<int>& nums, vector<int> vec, int index)
    {

        if(index<nums.size())
        {
            vector<int> localVec1(vec.begin(),vec.end());
            generateSubsets(nums, localVec1, index+1);
        
            vector<int> localVec2(vec.begin(),vec.end());
            localVec2.push_back(nums[index]);
            generateSubsets(nums, localVec2, index+1);
        }
        else
        {
            mat.push_back(vec);
        }
        
            
    }
};
