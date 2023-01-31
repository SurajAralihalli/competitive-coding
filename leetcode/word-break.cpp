// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/word-break/
// Date: 21st November, 2021
// Tags: dp, hash-table

// Approach 2
class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        bool sol=   false;
        set<string> hash;
        int n = s.size();
        vector<bool> dp(n+1,false);
        for(string w: wordDict)
        {
            hash.insert(w);
        }
        
        for(int j=0; j < n; j++)
         {
            for(int l=1; j+l <= n; l++)
             {
                 int b = j;
                 int e = j + l - 1;
                 // first index or b-1 index
                 if(b == 0 || dp[b-1]==true)
                 {
                    string w = s.substr(j, l);
                    if(hash.find(w)!=hash.end())
                    {
                        cout << w << " " << b << " " << e << endl;
                        dp[e] = true;
                    }
                 }
             }
         }

         for(int i=0;i<n;i++)
         {
             cout << dp[i] << " ";
         }
         cout << endl;
    
        return dp[n-1];
    }
    
};


// Approach 1
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
