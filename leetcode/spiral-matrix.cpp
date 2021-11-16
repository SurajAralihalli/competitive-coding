
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/spiral-matrix/
// Date: 16th November, 2021
// Tags: matrix, spiral

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int up=0;
        int down= n-1;
        int left = 0;
        int right = m-1;
        
        
        while(ans.size()<n*m)
            
        {
            //cout << up << " " << down << " " << left << " " << down << endl;
            for(int j=left;j<=right && ans.size()<n*m;j++)
            {
                ans.push_back(matrix[up][j]);
            }
            for(int i=up+1;i<=down && ans.size()<n*m;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            
            for(int j=right-1;j>=left && ans.size()<n*m;j--)
            {
                ans.push_back(matrix[down][j]);
            }
            for(int i=down-1;i>up && ans.size()<n*m;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            
            left++;
            right--;
            up++;
            down--;
            

        }
        
       
        
        return ans;
    }
};
