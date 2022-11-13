// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/restore-ip-addresses/
// Date: 13th Nov, 2021
// Tags: backtracking

class Solution {
public:
    vector<string> sol;
    int n;
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        dfs(s,"",0,0);
        return sol;
    }
    
    void dfs(string s, string path, int index, int quarter)
    {
        if(index==n && quarter==4)
        {
            sol.push_back(path.substr(0,path.size()-1));
        }
        else if(index<n)
        {
            string a = s.substr(index,1);
            string b = s.substr(index,2);
            string c = s.substr(index,3);
            
            dfs(s, path+a+".", index+1, quarter+1);
            
            if(b[0]!='0')
            {
                dfs(s, path+b+".", index+2, quarter+1);
            }
            
            if(c[0]!='0' && stoi(c)<=255)
            {
                dfs(s, path+c+".", index+3, quarter+1);
            }
        }
            
    }
};
