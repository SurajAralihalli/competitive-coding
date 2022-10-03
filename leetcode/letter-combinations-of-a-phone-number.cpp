// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Date: 2nd Oct, 2022
// Tags: backtracking, recursion

class Solution {
public:
    vector<string> sol;
    unordered_map<char,vector<char>> map;
    vector<string> letterCombinations(string digits) {
        map['2'] = {'a','b','c'};
        map['3'] = {'d','e','f'};
        map['4'] = {'g','h','i'};
        map['5'] = {'j','k','l'};
        map['6'] = {'m','n','o'};
        map['7'] = {'p','q','r','s'};
        map['8'] = {'t','u','v'};
        map['9'] = {'w','x','y','z'};
        
        dfs(digits, 0, "");
        
        return sol;
    }
    
    void dfs(string digits, int index, string s)
    {
        int n = digits.size();
        if(index==n && n!=0)
        {
            sol.push_back(s);
            return;
        }
        else if(index>n)
        {
            return;
        }
        
        for(char c : map[digits[index]])
        {
            s.push_back(c);
            dfs(digits, index+1, s);
            s.pop_back();
        }
        
    }
};
