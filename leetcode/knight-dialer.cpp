// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/knight-dialer/
// Date: 30th September, 2022
// Tags: dp

class Solution {
public:
    int knightDialer(int n) {
        unordered_map<int,vector<int>> map;
        map[0] = {6,4};
        map[1] = {6,8};
        map[2] = {7,9};
        map[3] = {4,8};
        map[4] = {0,3,9};
        map[5] = {};
        map[6] = {0,1,7};
        map[7] = {2,6};
        map[8] = {1,3};
        map[9] = {2,4};
        
        vector<vector<int>> mat(10,vector<int>(n+1,0));
        for(int i=0;i<=9;i++)
        {
            mat[i][0]=0;
            mat[i][1]=1;
        }
        
        
        for(int j=2;j<=n;j++)
        {
            for(int i=0;i<=9;i++)
            {
                int sum =0;
                
                for(int k:map[i])
                {
                    sum = ((sum % (int) (pow(10,9)+7))  + (mat[k][j-1] % (int) (pow(10,9)+7)));
                }
                
                mat[i][j] = sum;
            }
        }
        
        int count=0;
        for(int i=0;i<=9;i++)
        {
            count = (count % (int) (pow(10,9)+7))  + (mat[i][n] % (int) (pow(10,9)+7));
        }
        
        return count % (int) (pow(10,9)+7);
    }
};
