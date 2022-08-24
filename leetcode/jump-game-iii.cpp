// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/jump-game-iii/
// Date: 24th August, 2022
// Tags: dp, dfs, bfs

class Solution {
public:
    vector<int> marked;
    int n;
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        marked.assign(n,-1);
        return dp(arr, start);
        
    }
    
    int dp(vector<int>& arr, int index)
    {
        // out of bounds
        if(index>=n || index <0)
        {
            return 0;
        }
        // reached destination
        else if(arr[index] == 0)
        {
            marked[index] = 1;
            return marked[index];
        }
        // already processed
        else if(marked[index]==1 || marked[index]==0)
        {
            return marked[index];
        }
        // under processing / dont take this path
        else if(marked[index]==-2)
        {
            return 0;
        }
        // processing first time
        else
        {
            marked[index] = -2;
            bool isReachable = dp(arr, index + arr[index]);
            if(isReachable == 0)
            {
              isReachable = dp(arr, index - arr[index]);
            }
            
            marked[index] = isReachable;
            return marked[index];
        }
        
    }
    
};
