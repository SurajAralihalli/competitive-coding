// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/interleaving-string/
// Date: 2nd June, 2021
// Tags: 


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