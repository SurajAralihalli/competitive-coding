// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/set-matrix-zeroes/
// Date: 20th November, 2021
// Tags: array, matrix, hash-table

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // vector<pair<int,int>> vec;
        int n = matrix.size();
        int m = matrix[0].size();
        set<int> rows;
        set<int> columns;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        
        for(int i:rows)
        {
            for(int j=0;j<m;j++)
            {
                matrix[i][j] =0;
            }
        }
        
        for(int i:columns)
        {
            for(int j=0;j<n;j++)
            {
                matrix[j][i] =0;
            }
        }
        
    }
};
