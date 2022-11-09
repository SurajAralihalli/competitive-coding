// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/sparse-matrix-multiplication/
// Date: 9th Nov, 2022
// Tags: matrix-multiplication

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int p = mat1.size();
        int q = mat1[0].size();
        int r = mat2[0].size();
        
        vector<vector<int>> mat(p, vector<int>(r,0));
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<r;j++)
            {
                for(int k=0;k<q;k++)
                {
                    mat[i][j] += mat1[i][k] * mat2[k][j]; 
                }
            }                
        }
        
        return mat;
    }
};
