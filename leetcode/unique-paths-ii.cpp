// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/unique-paths-ii/
// Date: 16th May, 2021
// Tags: DP


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector< vector<int>> matrix;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        matrix.assign(m,vector<int>(n,0));
        for(int i=0;i<m;i++) {
            if(obstacleGrid[i][0]){break;}
            matrix[i][0]=1;
        }
        for(int i=0;i<n;i++) {
            if(obstacleGrid[0][i]){break;}
            matrix[0][i]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(!obstacleGrid[i][j]){
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
                }
            }
        }
        return matrix[m-1][n-1];
    }
    
};