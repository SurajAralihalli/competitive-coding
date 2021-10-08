// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/minimum-window-substring/
// Date: 8th October, 2021
// Tags: variable-sliding-window
  
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int i=0;
        int j=0;
        unordered_map<char,int> map;
        
        
        for(char i:t)
        {
            if(map.find(i)==map.end())
            {
                map[i]=0;
            }
            map[i]++;
        }
        int mini = INT_MAX;
        int k = map.size();
        int min_i=0;
        int min_j=0;
        while(j<n)
        {
            if(map.find(s[j])!=map.end())
            {
               
                if(map[s[j]]<0) //i have it in abundance and adding to the windiow makes no difference to unique elements
                {
                    map[s[j]]--;
                }
                else if(map[s[j]]==1) //adding it will eliminate the need for that s[i]
                {
                    map[s[j]]--;
                    k--;
                    // cout << "hhere "<<s[j] << j << endl;
                }
                else
                {
                    map[s[j]]--;
                }
                 
            }
            if(k>0)
            {
                j++;
            }
            else if(k==0)
            {
                // mini = min(mini,j-i+1);
                
                while(k==0)
                {
                    
                    if(mini != min(mini,j-i+1))
                    {
                        mini = min(mini,j-i+1);
                        min_i = i;
                        min_j = j;
                    };
                    
                    if(map.find(s[i])!=map.end())
                    {
                        if(map[s[i]]==0) // removing the s[i] will create a need 
                        {
                            k++;
                            map[s[i]]++;
                        }
                        else if(map[s[i]]>0)
                        {
                            map[s[i]]++;
                        }
                        else if(map[s[i]]<0)
                        {
                            map[s[i]]++;
                        }
                    }
                    i++;
                }
                j++;
            }
            
            
        }
        // cout << mini << endl;
        return mini!=INT_MAX?s.substr(min_i,mini):"";
    }
};
