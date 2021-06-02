// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/interleaving-string/
// Date: 2nd June, 2021
// Tags: memoization, dp


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector< vector <int> > memo;
        memo.assign(s1.size(),vector<int>(s2.size(),-1));
        
        return help(0,0,0,s1,s2,s3,memo);
    }
    static bool help(int s1i, int s2i,int s3i, string s1, string s2, string s3, vector< vector <int> >& memo )
    {
        if(s3i==s3.size() && s2i==s2.size() && s1i==s1.size()){return true;}
        
        if(s1i==s1.size())
        {
            return (s2.substr(s2i) == s3.substr(s3i));
        }
        if(s2i==s2.size())
        {
            return (s1.substr(s1i) == s3.substr(s3i));
        }

        if(memo[s1i][s2i]==-1)
        {
            bool ans = false;
            if(s1i<s1.size() && s3[s3i]==s1[s1i])
            {
                ans = ans || help(s1i+1, s2i, s3i+1, s1, s2, s3,memo );
            }
            if(s2i<s2.size() && s3[s3i]==s2[s2i])
            {
                ans = ans || help(s1i, s2i+1, s3i+1, s1, s2, s3,memo );
            }
            
            memo[s1i][s2i] = ans ? 1 : 0;
        }
        
        return (memo[s1i][s2i] ==1) ? true : false;
        
    }
};