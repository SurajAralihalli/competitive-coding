// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/longest-common-prefix/
// Date: 15th May, 2021

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int l = strs.size();
        string comm =strs[0];
        for(int i=1;i<l;i++)
        {
            string newc;
            int mini = min(comm.size(),strs[i].size());
            for(int j=0;j<mini;j++)
            {
                if(comm[j]==strs[i][j])
                {
                    newc += comm[j]; 
                }
                else{
                    break;
                }
                
            }
            comm = newc;
            if(comm.size()==0)
            {
                break;
            }
            
        }
        return comm;
    }
};