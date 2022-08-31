// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/reverse-words-in-a-string/
// Date: 31st August, 2022
// Tags: string

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string token;
        string sol = "";
        while(getline(ss, token, ' '))
        {
            if(token.size()!=0)
            {
                sol = token + " " + sol;
            }
        }
        
        return sol.substr(0, sol.size()-1);
    }
};
