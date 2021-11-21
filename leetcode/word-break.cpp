// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/word-break/
// Date: 21st November, 2021
// Tags: dp, hash-table


class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        bool sol=   false;
        set<string> hash;
        int n = s.size();
        vector<bool> dp(n+1,false);
        dp[0] = true;
         for(string w: wordDict)
         {
             hash.insert(w);
         }
            
         for(int i=1;i<=n;i++)
         {
             for(int j=0;j<i;j++)
             {
                 if(dp[j]==true)
                 {
                    string w = s.substr(j,i-j);
                    // cout << j << " " << i-j-1 << " " << w << endl;
                    if(hash.find(w)!=hash.end())
                    {
                        // cout << w << " " << i << endl;
                        dp[i] = true;
                        break;
                    }
                 }
             }
         }
         
    
         return dp[n];
    }
    
};
