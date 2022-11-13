// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/roman-to-integer/
// Date: 12th Nov, 2022
// Tags: recursion, hash-table, string

class Solution {
public:
    unordered_map<char, int> map;
    
    int romanToInt(string s) {
        
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        
        if(s=="")
        {
            return 0;
        }
        else
        {
            char c = s[0];
            if(c=='I')
            {
                if(s.size()>=2 && (s[1]=='V' || s[1]=='X'))
                {
                    return -1 * map[c] + romanToInt(s.substr(1)); 
                }
                else
                {
                    return map[c] + romanToInt(s.substr(1)); 
                }
            }
            else if(c=='X')
            {
                if(s.size()>=2 && (s[1]=='L' || s[1]=='C'))
                {
                    return -1 * map[c] + romanToInt(s.substr(1)); 
                }
                else
                {
                    return map[c] + romanToInt(s.substr(1)); 
                }
            }
            else if(c=='C')
            {
                if(s.size()>=2 && (s[1]=='D' || s[1]=='M'))
                {
                    return -1 * map[c] + romanToInt(s.substr(1)); 
                }
                else
                {
                    return map[c] + romanToInt(s.substr(1)); 
                }
            }
            else
            {
                return map[c] + romanToInt(s.substr(1)); 
            }
        }
            
    }
};
