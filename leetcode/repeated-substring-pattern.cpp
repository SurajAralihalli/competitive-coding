// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/repeated-substring-pattern/
// Date: 5th December, 2021
// Tags: string-matching

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string big = s+s;
        big.pop_back();
        big = big.substr(1);
        if(big.find(s)==big.npos)
        {
            return false;
        }
        return true;
    }
};
