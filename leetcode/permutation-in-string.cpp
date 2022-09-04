// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/permutation-in-string/
// Date: 4th Sept, 2021
// Tags: sliding-window

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int ns1 = s1.size();
        int ns2 = s2.size();
        
        vector<int> S1(26,0);
        vector<int> S2(26,0);
        
        for(char c: s1)
        {
            S1[c-'a']++;
        }
        
        int i=0;
        int j=0;
        while(j<ns2)
        {
            int w = j - i + 1;            
            S2[s2[j]-'a']++;
            if(w<ns1)
            {
                j++;
            }
            else if(w==ns1)
            {
                if(checkCondition(S1,S2))
                {
                    return true;
                }
                j++;
                S2[s2[i]-'a']--;
                i++;
            }
        }
        return false;
    }
    
    bool checkCondition(vector<int>& S1, vector<int>& S2)
    {
        for(int i=0;i<26;i++)
        {
            if(S1[i]!=S2[i])
            {
                return false;
            }
        }
        return true;
    }
};
