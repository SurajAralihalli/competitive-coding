// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/rectangle-overlap/description/
// Date: 20th February, 2023
// Tags: math, geometry

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        int left = max(rec1[0], rec2[0]);
        int right = min(rec1[2], rec2[2]);
        int x_overlap = right - left;

        int bottom =  max(rec1[1], rec2[1]);
        int top = min(rec1[3], rec2[3]);
        int y_overlap = top - bottom;
        
        return x_overlap > 0 && y_overlap > 0;
    }
};
