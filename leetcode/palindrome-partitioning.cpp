// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/palindrome-partitioning/
// Date: 2nd Oct, 2022
// Tags: backtracking, recursion

class Solution {
public:
    vector<vector<string>> sol;
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        dfs(s, 0, tmp);
        return sol;
    }
    
    void dfs(string s, int index, vector<string> vec)
    {
        int n = s.size();
        if(index==n)
        {
            sol.push_back(vec);
            return;
        }
        else if(index>n)
        {
            return;
        }
        
        for(int i=index;i<n;i++)
        {
            string sub = s.substr(index, i-index+1);
            if(isPalindrome(sub))
            {
                vec.push_back(sub);
                dfs(s, i+1, vec);
                vec.pop_back();
            }
        }
    }
    
    bool isPalindrome(string sub)
    {
        int n = sub.size();
        int l=0;
        int r =n-1;
        while(l<=r)
        {
            if(sub[l]!=sub[r])
            {
                return false;
            }
            l++;
            r--;
        }
        
        return true;
        
    }
};
