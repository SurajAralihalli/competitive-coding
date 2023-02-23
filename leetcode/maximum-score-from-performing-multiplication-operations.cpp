// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/description/
// Date: 23rd Feb, 2021
// Tags: dp

class Solution {
public:
    vector<vector<int>> dp;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        dp.assign(n, vector<int> (m, INT_MIN)); // 2D array is ufficient because when l is fixed, r is also fixed
        return recur(nums, multipliers, 0, n-1, 0);
    }

    int recur(vector<int>& nums, vector<int>& multipliers, int l, int r, int i) {
        int m = multipliers.size();
        if(i >= m) {
            return 0;
        }
        else if(l>r){
            return 0;
        }
        else if(dp[l][i]!=INT_MIN) {
            return dp[l][i];
        }
        else if(l==r) {
            int left = (nums[l] * multipliers[i]) + recur(nums, multipliers, l+1, r, i+1);
            dp[l][i] = left;
            return dp[l][i];
        }
        else {
            int left = (nums[l] * multipliers[i]) + recur(nums, multipliers, l+1, r, i+1);
            int right = (nums[r] * multipliers[i]) + recur(nums, multipliers, l, r-1, i+1);
            dp[l][i] =  max(left, right);
            return dp[l][i];
        }
    }
};
