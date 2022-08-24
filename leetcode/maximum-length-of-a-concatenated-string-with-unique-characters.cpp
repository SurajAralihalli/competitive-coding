// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// Date: 24th August, 2022
// Tags: backtracking

class Solution {
public:
    int maxUnique;
    int maxLength(vector<string>& arr) {
        maxUnique = 0;
        vector<int> charMap(26, 0);
        backtracking(charMap, arr, 0);
        return maxUnique;
    }
    
    void backtracking(vector<int> charMap, vector<string>& arr, int index)
    {
        for(int i = index; i < arr.size(); i++)
        {
            
            //compatible
            if(checkCompatible(charMap, arr[i]))
            {
                for(char c : arr[i])
                {
                    charMap[c - 'a'] = 1;
                }
                maxUnique = max(maxUnique, accumulate(charMap.begin(), charMap.end(), 0));
                
                backtracking(charMap, arr, i + 1);
                
                for(char c : arr[i])
                {
                    charMap[c - 'a'] = 0;
                }
            }
            
        }
    }
    
    bool checkCompatible(vector<int>& charMap, string s)
    {
        vector<int> duplicate(charMap.begin(), charMap.end());
        for(char c : s)
        {
            if(duplicate[c-'a'] == 1)
            {
                return false;
            }
            duplicate[c-'a'] = 1;
        }
        return true;
    }
        
};
