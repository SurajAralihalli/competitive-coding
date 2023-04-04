
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/partition-equal-subset-sum/
// Date: 6th September, 2021
// Tags: dp

// Approach 1
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        vector<vector<bool>> mat;
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%2) return false;
        sum/=2;
        mat.assign(n+1, vector<bool> (sum+1, false));
        for(int i=0;i<n;i++) {
            mat[i][0] = true;
        }

        for(int i=1; i<=n; i++) {
            for(int j=1;j<=sum;j++) {
                if(nums[i-1]<=j) {
                    mat[i][j] = mat[i-1][j] || mat[i-1][j - nums[i-1]];
                }
                else {
                    mat[i][j] = mat[i-1][j];
                }
            }
        }

        return mat[n][sum];


    }
};

// Approach 2
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
