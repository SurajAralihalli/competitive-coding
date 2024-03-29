// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/3sum/
// Date: 16th May, 2021
// Tags: 2 pointers

//Approach 1
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            // already included
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum==0)
                {
                    sol.push_back({nums[i], nums[l], nums[r]});
                    int L = nums[l];
                    
                    // avoid duplicates
                    while(nums[l]==L && l<r)
                    {
                        l++;
                    }
                }
                else if(sum>0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return sol;
    }
};

//Approach 1
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> matrix;
        matrix.reserve(nums.size()/(int)3);
        sort(nums.begin(),nums.end());
        int t = nums.size();
        int l;
        int r;
        int prev_val;

        for(int i=0; i<t-1;i++)
        {
        l = i+1;
        r = t-1;
        if(prev_val == nums[i]) {continue;}
        int prev_a = INT_MIN;
        int prev_b = INT_MAX;
         while(l<r)
            {
                int a = nums[l];
                int b = nums[r];
                int x = nums[i];
                if(prev_a == a) {l++;continue;}
                if(prev_b == b) {r--;continue;}
                // cout << "i: "<< i << " " << x << " " << a << " " << b << endl;
                if(a+b+x==0)
                {
                    vector<int> temp = {a,b,x};
                    matrix.push_back(temp);
                    prev_a = a;
                    prev_b =b;
                    r--;
                    l++;
                }
                else if(a+b+x > 0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
            prev_val = nums[i];
        }
        return matrix;
    }
};
