
// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/first-missing-positive/
// Date: 4th August, 2021
// Tags: array, linear-time

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n; i++)
        {
            if(nums[i]<=0)
            {
                nums[i] = INT_MAX-1;
            }  
        }
        for(int i=0;i<n; i++)
        {   
            if( abs(nums[i]) >= 1 && abs(nums[i])<= n+1 && abs(nums[i])<=n)
            {
                nums[abs(nums[i])-1] = -1 * abs(nums[abs(nums[i])-1]);
            }
        } 
        int ans =1;
        for(int i=0; i<n; i++)
        {
            if(nums[i]<0)
            {
                ans++;
            }
            else{
                break;
            }
        }         
        return ans;
    }          
};
