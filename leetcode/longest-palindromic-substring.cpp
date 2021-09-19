// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/longest-palindromic-substring/
// Date: 10th May, 2021
// Tags: DP, sliding-window

class Solution {
public:
    string longestPalindrome(string s) {
        vector< vector<int>> matrix;
        matrix.assign(s.size(),vector<int>(s.size(),0));
        int l = s.size();
        string str = s;
        int max_s =0;
        int max_e =0;
        int max_l = 0;
        for(int i=0;i<l;i++)
        {
            matrix[i][i]=1;
        }
        for(int ls=1;ls<=l;ls++)
        {
            for(int s=0;s <= l-ls ; s++ )
            {
                int e = s + ls -1;
                if(ls==1)
                {
                    matrix[s][e]=1;
                    max_s = s;
                    max_e = e;
                    max_l=ls;
                    
                }
                else if (ls==2)
                {
                    if(str[s]==str[e])
                    {
                        matrix[s][e]=1;
                        max_s = s;
                        max_e = e;
                        max_l=ls;
                    }
                }
                else
                {
                    if((str[s] == str[e]) && (matrix[s+1][e-1]==1))
                    {
                        matrix[s][e]=1;
                        max_s = s;
                        max_e = e;
                        max_l=ls;
                    }
                }
            }
        }
        // for(int i =0;i<l;i++)
        // {
        //     for(int j=0;j<l;j++)
        //     {
        //         cout << matrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return s.substr(max_s,max_l);
        
    }
};
