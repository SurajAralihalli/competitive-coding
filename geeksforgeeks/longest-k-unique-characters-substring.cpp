// Author: Suraj Aralihalli
// Url: https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
// Date: 21st September, 2021
// Tags: sliding-window

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    // unordered_map<char,int> map;
    vector<int> hash(26,0);
    int n = s.size();
    int i=0;
    int j=0;
    int unique_char=0;
    int maxi = INT_MIN;
    while(j<n)
    {
        if(hash[s[j]-'a']==0)
        {
            unique_char++;
        }
        
        hash[s[j]-'a']++;
        
        if(unique_char<k)
        {
            j++;
        }
        else if(unique_char>k)
        {
            while(unique_char>k)
            {
                hash[s[i]-'a']--;
                if(hash[s[i]-'a']==0) 
                {
                    unique_char--;
                }
                i++;
            }
            j++;
        }
        else if (unique_char==k)
        {
            // cout << "here " << i << " " << j << endl;
            maxi = max(maxi,(j-i+1));
            // i++;
            j++;
        }
    }
    
    maxi = (maxi==INT_MIN)?-1:maxi;
    return maxi;
    }
};
