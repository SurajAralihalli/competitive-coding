// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/target-sum/
// Date: 8th September, 2021
// Tags: dp, subset-count

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int count_zeros =0;
        // sort(nums.begin(),nums.end(),greater<int>());
        vector<int> new_nums;
        for(int i:nums)
        {
            sum+=i;
            if(i==0)
            {
                count_zeros++;
            }
            else
            {
                new_nums.push_back(i);
            }
        }
        
        target = abs(target);
        nums = new_nums;
        if(target>sum) return 0;
        if((target+sum)%2) return 0;
        int req = (target+sum)/2;
        
        
        int n = nums.size();
        vector< vector<int> >dp;
        dp.assign(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=nums[i-1])
                {
                    dp[i][j]=(dp[i-1][j-nums[i-1]]+dp[i-1][j]);
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int x = (dp[n][req]);
        // for(auto i:dp)
        // {
        //     for(auto j: i )
        //     {
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        return x*pow(2,count_zeros);
        
    }
};
