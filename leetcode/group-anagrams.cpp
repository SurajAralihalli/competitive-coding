// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/group-anagrams/
// Date: 21th May, 2021
// Tags: hash, to_string

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> matrix;
        unordered_map < string, vector<string> > map;
        for (string i: strs)
        {
            
            string key = "";
            vector <int> temp (26,0); 
            for(char j: i)
            {
                temp[int(j)-int('a')]++;
            }
            for(int x: temp)
            {
                key += "#";
                key += to_string(x);
            }
            
            // string dummy =i;
            // sort(dummy.begin(),dummy.end());
            // map[dummy].push_back(i);
            map[key].push_back(i);
        }
        for(auto i: map)
        {
            matrix.push_back(i.second);
        }
        return matrix;
        
        
    }
};