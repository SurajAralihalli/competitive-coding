
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/partition-equal-subset-sum/
// Date: 6th September, 2021
// Tags: dp


class Solution {
public:
    vector<vector<int>> mat;
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2!=0) return false;
        sum = sum/2;
        int n = nums.size();
        mat.assign(n+1,vector<int>(sum+1,-1));
        subset_sum(sum,n,nums);
        return mat[n][sum];
        
    }
    bool subset_sum(int sum, int n,vector<int>& nums)
    {
        if(mat[n][sum]!=-1) return mat[n][sum];
        if(sum==0)
        {
            mat[n][sum] = true; 
        }
        else if (n==0)
        {
            mat[n][sum] = false;
        }
        else if(nums[n-1]<=sum)
        {
            mat[n][sum] = subset_sum(sum - nums[n-1], n-1, nums) || subset_sum(sum, n-1, nums);
        }
        else
        {
            mat[n][sum] = subset_sum(sum, n-1, nums);
        }
        
        return mat[n][sum];
        
        
    }
};
