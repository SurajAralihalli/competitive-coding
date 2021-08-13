// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/edit-distance/
// Date: 13th August, 2021
// Tags: dp


class Solution {
public:
    int minDistance(string word1, string word2) {
        int l= word1.size();
        int m = word2.size();
        vector< vector<int> > mat;
        mat.assign(l + 1, vector<int> (m+1,0));
        
        for(int i=0;i<l+1;i++)
        {
            mat[i][0] = i;
        }
        
        for(int i=0;i<m+1;i++)
        {
            mat[0][i] =i;
        }
        
        for(int i =1;i<l+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    mat[i][j] = mat[i-1][j-1];
                }
                
                else
                {
                    int temp =min(mat[i-1][j],mat[i][j-1]);
                    temp = min(temp, mat[i-1][j-1]);
                    mat[i][j] = temp +1;
                }
            }
        }
        
//         for(int i=0;i<l+1;i++)
//         {
//             for(int j=0;j<m+1;j++)
//             {
//                 cout << mat[i][j] << " ";
//             }
            
//             cout << endl;
//         }
        
        return mat[l][m];
    }
};
