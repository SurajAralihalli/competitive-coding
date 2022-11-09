// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
// Date: 8th Nov, 2022
// Tags: anagrams, anagram, string, hash-table, hash

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> map;
        for(char c: s)
        {
            map[c]++;
        }
        
        for(char c: t)
        {
            map[c]--;
        }
        
        int count = 0;
        for(auto i:map)
        {
            count += abs(i.second);
        }
        
        return count/2;
    }
};
