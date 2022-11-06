// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/two-city-scheduling/
// Date: 6th Nov, 2022
// Tags: greedy, brute


//Approach 2



//Approach 1
class Solution {
public:
    int n;
    int twoCitySchedCost(vector<vector<int>>& costs) {
        n = costs.size()/2;
        return schedule(costs, 0, 0, 0, 0, 0);
    }
    
    int schedule(vector<vector<int>>& costs, int index, int costA, int nA, int costB, int nB)
    {
        if(nA==n && nB==n)
        {
            return costA+costB;
        }
        else
        {
            int cost = INT_MAX;
            if(nA<n)
            {
                cost = schedule(costs, index+1, costA+costs[index][0], nA+1, costB, nB);
            }
            if(nB<n)
            {
                cost = min(cost, schedule(costs, index+1, costA, nA, costB+costs[index][1], nB+1));
            }
            
            return cost;
        }
    }
};
