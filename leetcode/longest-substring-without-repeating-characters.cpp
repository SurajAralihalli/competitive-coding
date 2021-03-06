// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Date: 9th May, 2021
// Tags: sliding-window

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int l = s.size();
        int window_size = 0;
        int maxi=0;
        for(int i=0;i<l;i++)
        {
            auto it = hash.find(s[i]);
            if(it==hash.end() || i - (it->second) > window_size )
            {
                hash[s[i]]=i;
                window_size ++;
                maxi = max(maxi,window_size);
            }
            else if(it!=hash.end() && i - (it->second) <= window_size)
            {
                
                window_size = i - hash[s[i]];
                hash[s[i]]=i;
                maxi = max(maxi,window_size);
            }
        }
        return maxi;
    }
};



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n = s.size();
        int maxi = 0;
        unordered_map<char,int> map;
        while(j<n)
        {
            if(map.find(s[j])==map.end())
            {
                map[s[j]]=1;
                maxi = max(maxi,j-i+1);
                j++;
            }
            else
            {
                while(s[i]!=s[j])
                {
                    map.erase(map.find(s[i]));
                    i++;
                }
                i++;
                j++;
            }
            
        }
        return maxi;
    }
};
