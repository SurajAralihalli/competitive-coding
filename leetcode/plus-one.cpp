// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/plus-one/
// Date: 30th October, 2021
// Tags: arrays

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int prev =1;
        for(int i=n-1;i>=0;i--)
        {
            int v = digits[i]+prev;
            prev = v/10;
            v= v%10;
            digits[i] = v;
        }
        
        vector<int> ans;
        
        if(prev!=0)
        {
            ans.push_back(prev);
            ans.insert(ans.end(),digits.begin(),digits.end());
            digits = ans;
        }
        
        return digits;
    }
};
