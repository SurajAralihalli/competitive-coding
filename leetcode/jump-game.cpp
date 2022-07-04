// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/jump-game/
// Date: 20th May, 2021

// Approach 1
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> vec(nums.size(),0);
        for(int i=0;i<nums.size()-1;i++)
        {
            int h = vec[i];
            if(i!=0 && h==0) break;
            for(int j=1;j<=nums[i];j++)
            {
                if((i+j) < nums.size() && vec[i+j]==0)
                {
                vec[i+j] = (h + 1);
                }
            }
        }
        // for(int i=0;i<nums.size();i++)
        // {
        //     cout << vec[i] << " ";
        // }
        if(vec[nums.size()-1] || nums.size()==1)
        {
            return true;
        }
        return false;
    }
};

// Approach 2
class Solution {
public:
    vector<int> marked;
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        marked.assign(n,-1);
        return dp(nums,0)==1?true:false;        
    }
    
    int dp(vector<int>& nums, int index)
    {
        if(index>=nums.size()-1) 
        {
            return 1;
        }
        else if(marked[index]!=-1) 
        {
            return marked[index];
        }
        else
        {
            int flag =0;
            for(int i=1;i<=nums[index];i++)
            {
                if(dp(nums, index+i)==1)
                {
                    flag = 1;
                    break;
                }
            }
            
            marked[index] = flag;
            return marked[index];
        }
        
    }
};
