// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/unique-paths/
// Date: 16th May, 2021
// Tags: DP


class Solution {
public:
    int uniquePaths(int m, int n) {
     vector< vector<int>> matrix;
        matrix.assign(m,vector<int>(n,0));
        for(int i=0;i<m;i++) {matrix[i][0]=1;}
        for(int i=0;i<n;i++) {matrix[0][i]=1;}
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
            }
        }
        return matrix[m-1][n-1];
    }
};