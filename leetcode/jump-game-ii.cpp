// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/jump-game-ii/
// Date: 20th May, 2021

// Approach 1
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> vec(nums.size(),0);
        int n = nums.size();
        for(int j=1;j<n;j++)
        {
            int i=0;
            while(i<j)
            {
                int a = nums[i];
                if(i+a >= j)
                {
                    vec[j] = vec[i]+1;
                    break;
                }
                i++;
            }
        }
        return vec[n-1];
    }
};


// Approach 2
class Solution {
public:
    vector<int> marked;
    int jump(vector<int>& nums) {
        int n = nums.size();
        marked.assign(n,-1);
        return dp(nums,0);        
    }
    
    int dp(vector<int>& nums, int index)
    {
        if(index>=nums.size()-1) 
        {
            return 0;
        }
        else if(marked[index]!=-1) 
        {
            return marked[index];
        }
        else
        {
            int minSteps = INT_MAX-1;
            for(int i=1;i<=nums[index];i++)
            {
                
                minSteps = min(minSteps, dp(nums, index+i));
            }
            
            marked[index] = minSteps + 1;
            return marked[index];
        }
        
    }
};
