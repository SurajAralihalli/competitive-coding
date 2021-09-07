// Author: Suraj Aralihalli
// Url: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1#
// Date: 6th September, 2021
// Tags: dp

class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        vector< vector<int> >dp;
        dp.assign(n+1,vector<int>(sum+1,0));
        int y = int(pow(10,9)+7);
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(j>=arr[i-1])
                {
                    dp[i][j]=(dp[i-1][j-arr[i-1]]+dp[i-1][j])%y;
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int x = (dp[n][sum]);
        return x%y;
	}
	  
};
