// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/reducing-dishes/
// Date: 13th August, 2021
// Tags: dp

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int m = INT_MIN;
        for(int i=0; i < n; i++)
        {
            int c=0;
            // cout << i+1 << endl;
            int f=1;
            for(int j= i; j < n;j++)
            {
                c += satisfaction[j] * (f);
                f++;
                // cout << c << " ";
                m= max(m,c);
            }
            // cout << endl;
        }
        return m>0 ? m : 0;
    }
};
