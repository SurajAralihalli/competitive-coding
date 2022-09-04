// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/longest-repeating-character-replacement/
// Date: 4th September, 2022
// Tags: sliding-window

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0;
        int j=0;
        vector<int> map(26,0);
        int maxWindow =0;
        while(j<n)
        {
            int w = j - i + 1;
            map[s[j]-'A']++;
            //condition met
            if(checkCondition(map,k))
            {
                maxWindow = max(maxWindow, w);
                j++;
            }
            else
            {
                while(!checkCondition(map,k))
                {
                    map[s[i]-'A']--;
                    i++;
                }
                j++;
            }
        }
        return maxWindow;
        
    }
    
    bool checkCondition(vector<int>& map, int k)
    {
        int maxIndex = max_element(map.begin(), map.end()) - map.begin();
        for(int i=0;i<26;i++)
        {
            if(i!=maxIndex)
            {
                k -= map[i];
            }
        }
        
        return k>=0?true:false;
    }
};
