// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/open-the-lock/
// Date: 4th May, 2021
// Tags: bfs


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_map<string,bool> hash;
        for(auto i: deadends)
        {
            hash[i] = true;
            if(i=="0000"){ return -1;}
        }
        
        
        unordered_map<string,bool> map;
        int tar = stoi(target);
        queue<string> q;
        q.push("0000");
        map["0000"] = true;
        bool found = false;
        int level=-1;
        
        while(!q.empty())
        {
            int n = q.size();
            level++;
            for(int i=0;i<n;i++)
            {
                string ss = q.front();
                q.pop();
                // cout << ss << " ";
                if(ss==target) 
                {
                    found = true;
                    break;
                }
                for(int i=0;i<4;i++)
                {
                    string s = ss;
                    char a = add(s[i]);
                    char b = sub(s[i]);

                    s[i] = a;
                    if(map.find(s)==map.end() && hash.find(s)==hash.end())
                    {
                        q.push(s);
                        map[s] = true;
                    }
                    s[i] =b;
                    if(map.find(s)==map.end() && hash.find(s)==hash.end())
                    {
                        q.push(s);
                        map[s] = true;
                    }
                }
            }
            if(found){break;}
            // cout << endl;
      
        }
        
        if(found) { return level;}
        return -1;
        
    }
    
    static char add(char i)
    {
        if(i=='9'){
            return '0';
        }
        else
        {
            return char(i+1);
        }
    }
    
    static char sub(char i)
    {
        if(i=='0'){
            return '9';
        }
        else
        {
            return char(i-1);
        }
    }
};
