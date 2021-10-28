
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Date: 28th October, 2021
// Tags: stack


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<pair<int,int>> s;
        vector<int> left_arg_min;
        int n = prices.size();
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && s.top().first > prices[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                left_arg_min.push_back(-1);
            }
            else
            {
                left_arg_min.push_back(s.top().second);
            }
            s.push({prices[i],i});
        }
        
        int prev_index = -2;
        int val=0;
        int total_profit =0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++)
        {
            // cout << left_arg_min[i]<< " ";
            if(left_arg_min[i]!=-1)
            {
                
                    map[left_arg_min[i]] = max(map[left_arg_min[i]],prices[i]-prices[left_arg_min[i]]);
              
            }
        }
        cout << endl;
        for(auto i: map)
        {
            // cout << i.first << " " << i.second << endl;
            total_profit+= i.second;
        }
        return total_profit;
        
    }
};
