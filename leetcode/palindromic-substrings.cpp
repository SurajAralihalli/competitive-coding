// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/palindromic-substrings/
// Date: 29th July, 2022
// Tags: dp, string

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        vector<vector<int>> mat(n, vector<int> (n,0));
        for(int ls=1; ls<=n;ls++)
        {
            
            for(int b=0; b<= n-ls; b++)
            {
                int e = b + ls - 1;
                
                if(ls == 1) 
                {
                    mat[b][e] = 1;
                    count++;
                }
                else if(ls == 2)
                {
                    if(s[b] == s[e]) 
                    {
                        mat[b][e] = 1;
                        count ++;
                    }
                }
                else
                {
                    if(s[b] == s[e] && mat[b+1][e-1]==1) 
                    {
                        mat[b][e] = 1;
                        count ++;
                    }
                }
            }
        }
        
        return count;
    }
};
