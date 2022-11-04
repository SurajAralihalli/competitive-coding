// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/reorganize-string/
// Date: 4th Nov, 2021
// Tags: string, heap


class Solution {
public:
    string reorganizeString(string s) {
        // count, char
        priority_queue<pair<int,char>> readyQueue;
        unordered_map<char,int> map;
        for(char c:s)
        {
            map[c]++;
        }
        for(auto t:map)
        {
            readyQueue.push({t.second,t.first});
        }
        
        string result="";
        pair<int,char> prev = {0,'/'};
        while(!readyQueue.empty())
        {
            auto t = readyQueue.top();
            readyQueue.pop();
            char c = t.second;
            int count = t.first-1;
            // result
            result+=c;
            if(prev.first!=0)
            {
                readyQueue.push({prev.first, prev.second});
            }
            prev = {count,c};
        }
        
        if(prev.first==0)
        {
            return result;
        }
        else
        {
            return "";
        }
        
    }
};
