// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/
// Date: 5th April, 2023
// Tags: greedy

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> forbidden;
        int n = triplets.size();
        for(int i=0;i<n;i++) {
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]){
                forbidden.insert(i);
            }
        }

        vector<int> cur = {0, 0, 0};

        for(int i=0;i<n;i++) {
            if(forbidden.count(i)==0){
                cur[0] = max(cur[0], triplets[i][0]);
                cur[1] = max(cur[1], triplets[i][1]);
                cur[2] = max(cur[2], triplets[i][2]);
            }
        }

        if(cur[0] == target[0] && cur[1] == target[1] && cur[2] == target[2]) {
            return true;
        }

        return false;
    }
};
