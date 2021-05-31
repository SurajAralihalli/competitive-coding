// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/combination-sum/
// Date: 31th May, 2021
// Tags: backtracking




class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> matrix;
        vector<int> vec;
        sort(candidates.begin(),candidates.end());
        int index=0;
        help(candidates, matrix, vec, target, index);
        return matrix;
        
    }
    
    static void help(vector<int>& candidates,vector<vector<int>>& matrix,vector<int> vec, int sum, int index)
    {
        for(int i=index; i<candidates.size();i++)
        {
            
            
            if((sum-candidates[i])==0)
            {
                
                vector<int> local_vec;
                local_vec.assign(vec.begin(),vec.end());
                local_vec.push_back(candidates[i]);
                matrix.push_back(local_vec);
                
                index++;
                break;
            }
            else if((sum-candidates[i])>0)
            {
                vector<int> local_vec;
                local_vec.assign(vec.begin(),vec.end());
                local_vec.push_back(candidates[i]);
                help(candidates, matrix, local_vec, sum-candidates[i],i);
            }
            
            
        }
    }
};