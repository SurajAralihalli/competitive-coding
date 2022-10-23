// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
// Date: 23rd Oct, 2022
// Tags: dp, dfs


class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> visited;
    int n;
    int m;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        dp.assign(n, vector<int> (m,-1));
        visited.assign(n, vector<int> (m,0));
        
        int maxLength =0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                maxLength = max(maxLength,dfs(i,j,-1,matrix));
            }
        }
        
        return maxLength;
    }
    
    int dfs(int r, int c, int prev, vector<vector<int>>& matrix)
    {
        if(r<0 || r>=n || c<0 || c>=m || prev >= matrix[r][c] || visited[r][c]==1)
        {
            return 0;
        }
        if(dp[r][c]!=-1)
        {
            return dp[r][c];
        }
        else
        {
            visited[r][c]=1;
            dp[r][c] = 1 + max({
                            dfs(r+1,c,matrix[r][c],matrix),
                            dfs(r-1,c,matrix[r][c],matrix),
                            dfs(r,c+1,matrix[r][c],matrix),
                            dfs(r,c-1,matrix[r][c],matrix)
                            });
            visited[r][c]=0;
            
            return dp[r][c];
        }
    }
};
