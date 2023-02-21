// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/koko-eating-bananas/description/
// Date: 21st February, 2023
// Tags: binary-search


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int n = piles.size();

        int l = 1;
        int r = piles.back();
        int m;
        int sol = INT_MAX;
        while(l<=r) {
            m = (l+r)/2;
            int t=0;
            for(auto i : piles) {
                // t += ceil((float)i/m);
                t +=  (i/m) + (i % m != 0);
            }
            
            if(t>h){
                l = m+1;
            }
            else {
                r = m-1;
                sol = min(sol, m);
            }
        }

        return sol;
    }
};
