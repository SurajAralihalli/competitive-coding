// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/partition-labels/
// Date: 5th Nov, 2022
// Tags: greedy

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,vector<int>> map;
        int n=s.size();
        int i=0;
        for(char c:s)
        {
            map[c].push_back(i);
            i++;
        }
        
        int count=0;
        vector<int> sol;
        i=0;
       
        int partStartIndex = 0;
        char c = s[partStartIndex];
        int partEndIndex = map[c].back();
        while(true)
        {
            bool complete = true;
            for(int i=partStartIndex+1;i<=partEndIndex-1;i++)
            {
                c = s[i];
                int e = map[c].back();
                if(e>partEndIndex)
                {
                    partEndIndex = e;
                    complete = false;
                    break;
                }
            }
            
            if(complete)
            {
                sol.push_back(partEndIndex-partStartIndex+1);
                count++;
                partStartIndex = partEndIndex+1;
                
                if(partStartIndex>=n) break;
                
                c = s[partStartIndex];
                partEndIndex = map[c].back();
            }
        }
                
        return sol;
        
    }
};
