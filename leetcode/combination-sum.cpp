// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/combination-sum/
// Date: 31th May, 2021
// Tags: backtracking, recursion


// Approach 3
class Solution {
public:
    vector<vector<int>> sol;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vec;
        dfs(candidates, target, vec, 0);
        return sol;
    }
    
    void dfs(vector<int>& candidates, int target, vector<int> vec, int index)
    {
        if(target<0)
        {
            return;
        }
        
        if(target==0)
        {
            sol.push_back(vec);
            return;
        }
        
        for(int i=index;i<candidates.size();i++)
        {
            vec.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], vec, i);
            vec.pop_back();
        }
    }
};


// Approach 1 - with sort
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
            else
            {
                break;
            }
            
            
        }
    }
};


// Approach 2 - without sort
class Solution {
public:
    vector<vector<int>> mat;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vec;
        vec.clear();
        generateCombination(candidates, vec, target, 0);
        return mat;
    }
    
    void generateCombination(vector<int>& candidates, vector<int> vec, int target, int index)
    {
        for(int i=index;i<candidates.size();i++)
        {
            //reached solution
            if(target - candidates[i]==0)
            {
                vector<int> localVec(vec.begin(), vec.end());
                localVec.push_back(candidates[i]);
                mat.push_back(localVec);
            }
            //space for more
            else if(target - candidates[i]>0)
            {
                vector<int> localVec(vec.begin(), vec.end());
                localVec.push_back(candidates[i]);
                // can add candidates[i] to vec again
                generateCombination(candidates, localVec, target - candidates[i], i);
            }
         
        }
    }
};
