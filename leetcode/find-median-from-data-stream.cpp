// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/find-median-from-data-stream/
// Date: 7th October, 2021
// Tags: heaps, priority-queue

#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here


vector <int> findMedian(vector <int> arr) {
  // Write your code here
  priority_queue<int> small;
  priority_queue<int,vector<int>,greater<int>> large;
  vector<int> ans;
  int n = arr.size();
  for(int i=0;i<n;i++)
  {
    small.push(arr[i]);
    large.push(small.top());
    small.pop();
    if(large.size()>small.size())
    {
      small.push(large.top());
      large.pop();
    }
    
    if(small.size()>large.size())
    {
      ans.push_back(small.top());
    }
    else
    {
      ans.push_back((small.top()+large.top())/2);
    }
  }
  
  return ans;
  
}
