// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/subsets/
// Date: 29th June, 2022
// Tags: backtracking, recursion


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
