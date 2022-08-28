// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/rotate-array/
// Date: 28th August, 2022
// Tags: array, two-pointers

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
