// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/daily-temperatures/
// Date: 2nd April, 2023
// Tags: stack

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> sol;
        stack<int> stk;

        for(int i = temperatures.size()-1; i>=0; i--) {
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[i]) {
                stk.pop();
            }

            if(!stk.empty()) {
                sol.push_back(stk.top() - i);
            }
            else {
                sol.push_back(0);
            }

            stk.push(i);

        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};
