// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Date: 9th November, 2021
// Tags: binary-search

//Approach 1
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findmin(nums,0,nums.size()-1);
    }
    
    int findmin(vector<int>& nums, int l, int r)
    {
        int n = nums.size();
        if(n==1) return nums[0];
        while(l<=r)
        {
            int mid = (l+r)/2;
            int a = nums[l];
            int m = nums[mid];
            int b = nums[r];
            
            int prev = nums[(mid+1)%n];
            int nxt = nums[(mid+n-1)%n];
           
            // cout << mid << endl; 
            if(prev > m && nxt> m)
            {
                // cout << "here" << endl;
                return m;
            }
            else if(a < m && m < b)
            {
                return a;
            }
            else if(a<=m)
            {
                l = mid+1;
            }
            else if(m<=b)
            {
                r = mid-1;
            }
        }
        return -1;
    }
};

// Approach 2
class Solution {
public:
    int findMin(vector<int>& nums) {
        int minEle = INT_MAX;
        int n = nums.size();
        int l =0;
        int r = n-1;
        
        while(l<r)
        {
            if(nums[l] <= nums[r])
            {
                minEle = min(minEle, nums[l]);
                break;
            }
            
            int m = (l+r)/2;
            minEle = min(minEle, nums[m]);
            
            if(nums[m]>=nums[l])
            {
                l = m+1;
            }
            else
            {
                r = m-1;
            }
        }
        
        if(l==r)  minEle = min(minEle, nums[l]);
        
        return minEle;
    }
};
