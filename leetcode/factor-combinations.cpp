// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/factor-combinations/
// Date: 15th Nov, 2021
// Tags: backtracking


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
