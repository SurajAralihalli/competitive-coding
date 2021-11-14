// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/rotate-image/
// Date: 14th November, 2021
// Tags: array, matrix

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i!=j)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
