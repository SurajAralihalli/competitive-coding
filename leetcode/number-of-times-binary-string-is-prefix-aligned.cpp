// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/
// Date: 23rd August, 2022
// Tags: array


class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size();
        int count = 0;
        int rightMax = 0;
        for(int i=0;i<n;i++)
        {
            int b = flips[i];
            int indexOfb = i+1;
            
            rightMax = max(rightMax, b);
            if(indexOfb == rightMax)
            {
                count++;
            }
            
        }
        return count;
    }
};
