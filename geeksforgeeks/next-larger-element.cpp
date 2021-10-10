// Author: Suraj Aralihalli
// Url: https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#
// Date: 10th October, 2021
// Tags: stack


class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> ans;
        if(n<=0) return ans;
        
        stack<long long> s;
        // s.push(arr[0]);
        reverse(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && s.top()<=arr[i])
            {
                s.pop();
            }
            if(!s.empty())
            {
                ans.push_back(s.top());
                
            }
            else
            {
                ans.push_back((long long)(-1));
            }
            s.push(arr[i]);
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
