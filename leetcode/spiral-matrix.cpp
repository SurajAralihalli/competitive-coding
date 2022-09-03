
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/spiral-matrix/
// Date: 2nd September, 2022
// Tags: matrix, spiral

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0;
        int down = m-1;
        int left = 0;
        int right = n-1;
        int direction = 0;
        
        vector<int> vec;
        
        while(left<=right && top<=down)
        {
            if(direction == 0)
            {
                for(int i=left; i<=right; i++)
                {
                    vec.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(direction == 1)
            {
                for(int i=top; i<=down; i++)
                {
                    vec.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(direction == 2)
            {
                for(int i=right;i>=left; i--)
                {
                    vec.push_back(matrix[down][i]);
                }
                down--;
            }
            else
            {
                for(int i=down;i>=top;i--)
                {
                    vec.push_back(matrix[i][left]);
                }
                left++;
            }
            
            direction = (direction+1)%4;
        }
        
        return vec;
    }
};
