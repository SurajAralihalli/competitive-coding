// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/distinct-subsequences/
// Date: 24th Oct, 2022
// Tags: dp

//Approach 2

//Approach 1
class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int m;
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        
        dp.assign(n, vector<int>(m,-1));
        return dfs(0,0,s,t); 
    }
    
    int dfs(int s1, int s2, string s, string t)
    {
        if(s2==m)
        {
            return 1;
        }
        else if(s1>= n)
        {
            return 0;
        } 
        else if(dp[s1][s2]==-1)
        {
            if(s[s1]==t[s2])
            {
              dp[s1][s2] = dfs(s1+1,s2+1,s,t) +  dfs(s1+1,s2,s,t);
            }
            else
            {
                dp[s1][s2] = dfs(s1+1,s2,s,t);
            }
            
            return dp[s1][s2];
        }
        else
        {
            return dp[s1][s2];
        }
    }
};
