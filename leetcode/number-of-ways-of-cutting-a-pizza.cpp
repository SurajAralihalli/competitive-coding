// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
// Date: 12th Nov, 2022
// Tags: dp, prefix-sum

class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> prefixSum;
    int n;
    int m;
    int k;
    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].size();
        this->k = k;
        dp.assign(m, vector<vector<int>> (n, vector<int> (k+1,-1)));
        prefixSum.assign(m+1, vector<int> (n+1,0)); // prefixSum[r][c] = num of apples in prefixSum[r:][c:]
        for(int r=m-1; r>=0;r--)
        {
            for(int c=n-1;c>=0;c--)
            {
                prefixSum[r][c] = (pizza[r][c]=='A'?1:0) + prefixSum[r][c+1] + prefixSum[r+1][c] - prefixSum[r+1][c+1];
            }
        }
        
        return findCount(0,0,1);
        
    }
    
    int findCount(int i, int j, int slicesCount)
    {
        
        if(i>=m || i<0 || j>=n || j<0 || slicesCount>k || prefixSum[i][j]<=0)
        {
            return 0;
        }
        else if(slicesCount==k)
        {
            dp[i][j][slicesCount]=1;
            return dp[i][j][slicesCount];
        }
        else if(dp[i][j][slicesCount]!=-1)
        {
            return dp[i][j][slicesCount];
        }
        else
        {
            int count =0;
            for(int r=i+1;r<m;r++)
            {
                if(prefixSum[i][j] - prefixSum[r][j]>0)
                {
                    count = (count+findCount(r,j, slicesCount+1))%1000000007;
                }
                
            }
            
            for(int c=j+1;c<n;c++)
            {
                if(prefixSum[i][j] - prefixSum[i][c]>0)
                {
                    count = (count+findCount(i,c, slicesCount+1))%1000000007;
                }
            }
            
            dp[i][j][slicesCount] = count;
            return dp[i][j][slicesCount];
        } 
    }
};
