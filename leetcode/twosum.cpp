// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/two-sum/
// Date: 7th May, 2021
// Tags: sort

#include <bits/stdc++.h>
using namespace std;
struct box{
    int val;
    int index;
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<box> chain;
        chain.resize(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            box s;
            s.val = nums[i];
            s.index = i;
            chain[i] = s; 
        }
        sort(chain.begin(),chain.end(),sort_helper);
        int t =target;
        vector<int> answer;
        answer.resize(2);
        int f = 0;
        int l = nums.size()-1;
        while(f<l)
        {
            int sum = chain[f].val + chain[l].val;
            if(sum>target)
                l--;
            else if(sum<target)
                f++;
            else
                break;
        }
        answer[0]=chain[f].index;
        answer[1]=chain[l].index;
        return answer;
    }
    static bool sort_helper(box a,box b)
    {
        if(a.val<b.val)
            return true;
        else
            return false;
    }
};
