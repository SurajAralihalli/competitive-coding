// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/zigzag-conversion/
// Date: 11th May, 2021

class Solution {
public:
    string convert(string s, int numRows) {
        vector< string > matrix (numRows);
        // matrix.assign(numRows,string(""));
        int x =1;
        int index =0;
        for(int i=0;i<s.size();i++)
        {
            if (numRows==1)
            {
                x=0;
            }
            else if(index == numRows-1)
            {
                x=-1;
            }
        
            else if(index == 0)
            {
                x=1;
            }
            matrix[index] = matrix[index] + s[i];
            index = index + x;
            
        }
        string result;
        for(int i=0;i<numRows;i++)
        {
            result += matrix[i];
        }
        return result;
        
    }
};