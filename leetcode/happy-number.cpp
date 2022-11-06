// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/happy-number/
// Date: 6th Nov, 2022
// Tags: math, geometry

class Solution {
public:
    bool isHappy(int n) {
        set<int> mySet;
        
        while(n!=1)
        {
            if(mySet.count(n)==1)
            {
                return false;
            }
            
            mySet.insert(n);
            
            
            int c=0;
            while(n!=0)
            {
                c = c + pow(n%10,2);
                n = n/10;
            }
            n=c;
            
        }
        
        return true;
    }
};
