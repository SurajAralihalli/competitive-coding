// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/h-index/
// Date: 8th November, 2021
// Tags: sorting


class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int h=0;
        int i;
        for(i=0;i<n;i++)
        {
            int s = n - i;
            if(s>citations[i])
            {
                h = citations[i];
                
            }
            else if(s==citations[i])
            {
                return citations[i];
            }
            else
            {
                return s;
            }
            
        }
        return h;
    }
};
