// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/search-a-2d-matrix/description/
// Date: 21st February, 2021
// Tags: binary-search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int l = 0;
        int r = m*n - 1;

        while(l<=r) {
            int mid = (l+r)/2;
            
            int element = matrix[mid / n][mid % n];

            if(element==target) {
                return true;
            }
            else if(element<target) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }

        return false;
    }
};
