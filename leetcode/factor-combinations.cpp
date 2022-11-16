// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/factor-combinations/
// Date: 15th Nov, 2021
// Tags: backtracking

// Approach 2
class Solution {
public:
    vector<vector<int>> sol;
    int k;
    vector<vector<int>> getFactors(int n) {
        vector<int> vec;
        if(n==1) 
        {
            return {};
        }
        
        dfs(n,vec, 2, 1);
        return sol;
    }
    
    void dfs(int target, vector<int>& vec, int start, int productSoFar)
    {
        if(productSoFar==target)
        {
            sol.push_back(vec);
            return;
        }
        else
        {
            for(int i=start;i<target;i++)
            {
                long long v = (long long)productSoFar * (long long)i;
                if(v>target)
                {
                    break;
                }
                
                if(target%i==0)
                {
                    vec.push_back(i);
                    dfs(target,vec,i, productSoFar*i);
                    vec.pop_back();
                }
                
            }
        }
    }
};

// Approach 1
class Solution {
public:
    vector<vector<int>> sol;
    int k;
    vector<vector<int>> getFactors(int n) {
        vector<int> vec;

        if(n==1) 
        {
            return {};
        }
        
        dfs(n,vec, 2);
        return sol;
    }
    
    void dfs(int n, vector<int>& vec, int start)
    {
        if(n==1)
        {
            sol.push_back(vec);
        }

        else
        {
            for(int i=start;i<=n;i++)
            {
                if(i==n && vec.size()==0)
                {
                    continue;
                }
                if(n%i==0)
                {
                    
                    vec.push_back(i);
                    dfs(n/i, vec, i);
                    vec.pop_back();
                }
            }
        }
    }
};
