// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Date: 5th December, 2021
// Tags: dp

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> a(26,0);
        vector<int> b(26,0);
        
        for(char i:p)
        {
            b[i-'a']++;
        }
        
        int i=0;
        int j =0;
        vector<int> sol;
        

        
        while(j<n)
        {
            int w = j-i+1;
            a[s[j]-'a']++;

            if(w<m)
            {
                j++;
                
            }
            else
            {
                bool flag = true;
                for(int k=0;k<26;k++)
                {
                    
                    if(a[k]!=b[k])
                    {
                        flag = false;
                    }
                }
                
                if(flag)
                {
                    sol.push_back(i);
                }
                
                
                a[s[i]-'a']--;
                i++;
                j++;
            }
        }
        return sol;
    }
    
};
