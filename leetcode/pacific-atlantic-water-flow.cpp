// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/pacific-atlantic-water-flow/
// Date: 10th Oct, 2022
// Tags: graph, dfs

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> reachPacific(n, vector<int>(m,0));
        vector<vector<int>> reachAtlantic(n, vector<int>(m,0));
        
        vector<vector<int>> sol;
        
        for(int c=0;c<m;c++)
        {
            dfs(heights, reachPacific, 0, c,  heights[0][c]);
            dfs(heights, reachAtlantic, n-1, c,  heights[n-1][c]);
        }
        
        for(int r=0;r<n;r++)
        {
            dfs(heights, reachPacific, r, 0,  heights[r][0]);
            dfs(heights, reachAtlantic, r, m-1,  heights[r][m-1]);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(reachPacific[i][j]==1 && reachAtlantic[i][j]==1)
                {
                    sol.push_back({i,j});
                }
            }
        }
        
        return sol;
        
    }
    
    void dfs(vector<vector<int>>& heights,  vector<vector<int>>& reached, int i, int j, int prevHeight)
    {
        int n = heights.size();
        int m = heights[0].size();
        if(i>=n || i<0 || j>=m || j<0 || reached[i][j]==1 || heights[i][j]<prevHeight)
        {
            return;
        }
        else
        {
            reached[i][j]=1;
            dfs(heights, reached, i+1, j,  heights[i][j]);
            dfs(heights, reached, i-1, j,  heights[i][j]);
            dfs(heights, reached, i, j+1,  heights[i][j]);
            dfs(heights, reached, i, j-1,  heights[i][j]);
        }
        
    }
};
