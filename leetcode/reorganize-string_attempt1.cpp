// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/reorganize-string/
// Date: 29th May, 2021
// Tags: string


class Solution {
public:
    string reorganizeString(string s) {
        vector<int> map(26,0);
        for(char i: s)
        {
            map[int(i)-int('a')]+=1;
        }
        int n = s.size();
        int a =27;
        string f="";
        for(int i=0;i<n;i++)
        {
            bool flag=false;
            int o;
            int lmax =0;
            for(int j=0;j<26;j++ )
            {
                if(j!=a && map[j]>0)
                {
                    // cout << "here: " << char(j+int('a')) << endl;
                    if(map[j]>lmax)
                    {
                        o=j;
                        lmax = map[j];
                    }
                    flag=true;
                }
            }
            if(flag)
            {
                f+= char(o+int('a'));
                map[o]--;
                a = o;
            }
            
            
            else{return "";}
            
        }
        return f;
    }
};