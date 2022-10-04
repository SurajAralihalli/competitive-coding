// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/n-queens/
// Date: 3rd Oct, 2022
// Tags: backtracking, recursion

class Solution {
public:
    vector<vector<string>> sol;
    unordered_set<int> columnsFilled;
    unordered_set<int> positiveDiagFilled;
    unordered_set<int> negativeDiagFilled;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> vec(n, string(n,'.'));
        backtrack(n, 0, vec);
        return sol;
        
    }
    
    void backtrack(int n, int r, vector<string> vec)
    {
        if(r==n)
        {
            sol.push_back(vec);
            return;
        }
        for(int c=0;c<n;c++)
        {
            // condition to ensure previously placed queens do not attack
            if(columnsFilled.find(c)==columnsFilled.end() 
               && positiveDiagFilled.find(r+c)==positiveDiagFilled.end()
               && negativeDiagFilled.find(r-c)==negativeDiagFilled.end())
            {
                columnsFilled.insert(c);
                positiveDiagFilled.insert(r+c);
                negativeDiagFilled.insert(r-c);
                vec[r][c] = 'Q';
                
                backtrack(n, r+1, vec);
                
                columnsFilled.erase(c);
                positiveDiagFilled.erase(r+c);
                negativeDiagFilled.erase(r-c);
                vec[r][c] = '.';
                
            }
        }
    }
};
