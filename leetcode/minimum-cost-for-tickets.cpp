// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/minimum-cost-for-tickets/
// Date: 22nd June, 2021
// Tags: dp


class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,0);
        int day_index=0;
        for(int i=1;i<=365;i++)
        {
            if(i>days.back())
            {
                break;
            }
            
            if(i==days[day_index])
            {
                int prev1 = i-1;
                int prev7 = i-7;
                int prev30 = i-30;
                
                prev7 = prev7>0 ? prev7 : 0;
                prev30 = prev30>0 ? prev30:0;
                
                dp[i]=min(dp[prev1]+costs[0], dp[prev7]+costs[1]);
                dp[i] = min(dp[i],dp[prev30]+costs[2]);
                day_index++;
            }
            else
            {
               dp[i]=dp[i-1]; 
            }
            
        }
        
        return dp[days.back()];
    }
};
