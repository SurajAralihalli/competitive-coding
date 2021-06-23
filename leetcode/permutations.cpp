// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/permutations/
// Date: 23rd June, 2021
// Tags: backtracking

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
