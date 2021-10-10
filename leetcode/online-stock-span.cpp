// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/online-stock-span
// Date: 10th October, 2021
// Tags: stack

class StockSpanner {
public:
    stack <pair<int,int>> s;
    int index =0;
    StockSpanner() {
    }
    
    int next(int price) {
        while(!s.empty() && s.top().first<= price)
          {
              s.pop();
          }
          int greatest_left_index;
          if(s.empty())
          {
              greatest_left_index = -1;
          }
          else
          {
              greatest_left_index = s.top().second;
          }
        
        s.push(make_pair(price,index));
        int ans = index - greatest_left_index;
        index++;
        return ans;
    }
};
