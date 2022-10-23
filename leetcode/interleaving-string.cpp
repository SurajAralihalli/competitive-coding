// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/interleaving-string/
// Date: 2nd June, 2021
// Tags: 

// Approach 2
class Solution {
public:
    vector<vector<int>> dp;
    bool isInterleave(string s1, string s2, string s3) {
        dp.assign(s1.size()+1, vector<int>(s2.size()+1,-1));
        
        return dfs(s1,s2,s3,0,0,0);
    }
    
    bool dfs(string s1, string s2, string s3, int s1i, int s2i, int s3i)
    {
        if(s1i == s1.size() && s2i == s2.size() && s3i == s3.size())
        {
            return true;
        }
        else if(dp[s1i][s2i]==-1)
        {
            int flag =0;
            if(s1i < s1.size() && s1[s1i] == s3[s3i])
            {
                flag = flag || dfs(s1,s2,s3, s1i+1, s2i, s3i+1);
            }
            if(s2i < s2.size() && s2[s2i] == s3[s3i])
            {
                flag = flag || dfs(s1,s2,s3, s1i, s2i+1, s3i+1);
            }
            
            dp[s1i][s2i] = flag;
            return dp[s1i][s2i];
        }
        else
        {
            return dp[s1i][s2i];
        }   
    }
};


// Approach 1
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool found = false;
        help(0,0,0,s1,s2,s3,found);
        return found;
    }
    static void help(int s1i, int s2i,int s3i, string s1, string s2, string s3, bool& found )
    {
        if(s3i==s3.size() && s2i==s2.size() && s1i==s1.size()){found=true;}
        if(!found)
        {
            if(s1i<s1.size() && s3[s3i]==s1[s1i])
            {
                help(s1i+1, s2i, s3i+1, s1, s2, s3,found );
            }
            if(s2i<s2.size() && s3[s3i]==s2[s2i])
            {
                help(s1i, s2i+1, s3i+1, s1, s2, s3,found );
            }
        }
    }
};
