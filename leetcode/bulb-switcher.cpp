// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/bulb-switcher/
// Date: 23th August, 2022
// Tags: stack, math


class Solution {
public:
    int bulbSwitch(int n) {
        int count =0;
        for(int i=1;i<=n;i++)
        {
            int m = sqrt(i);
            if(m*m == i)
            {
                count ++;
            }
        }
        return count;
    }
};
