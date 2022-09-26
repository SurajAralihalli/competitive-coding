// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/car-fleet/
// Date: 25th September, 2022
// Tags: monotonic-stack


class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> arr;
        int n = position.size();
        for(int i=0;i<n;i++)
        {
            double timeToTarget = (target - position[i]) / speed[i];
            arr.push_back({position[i],timeToTarget});
        }
        sort(arr.begin(), arr.end());
        int fleet=0;
        
        int maxTime = -1; // maxtime of the cars on the right
        for(int j=n-1;j>=0;j--)
        {
            if(arr[j].second>maxTime) //will come as a different fleet else would join same fleet
            {
                maxTime = arr[j].second;
                fleet++;
            }
        }
        
        return fleet;
        
    }
};
