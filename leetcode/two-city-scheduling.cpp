// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/two-city-scheduling/
// Date: 6th Nov, 2022
// Tags: greedy, brute


//Approach 2
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), asc);
        int total=0;
        int n = costs.size()/2;
        for(int i =0;i<n;i++)
        {
            total += costs[i][0] + costs[i+n][1];
        }
        return total;
    }
    
    static bool asc(vector<int> p, vector<int> q)
    {
        return (p[0]-p[1] < q[0]-q[1]);
    }
};


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
