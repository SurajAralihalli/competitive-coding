// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/maximum-performance-of-a-team/
// Date: 19th June, 2021
// Tags: greedy, sort

#include <bits/stdc++.h>
using namespace std;

struct node{
    int s;
    int e;
};

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<node*> arr;
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int i=0;i<n;i++)
        {
            node* temp = new node();
            temp->s = speed[i];
            temp->e = efficiency[i];
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end(),func);
        
        long long maxi = 0;
      
        long long sum = 0;
        for(int i=0; i<n;i++)
        {
            int s = arr[i]->s;
            int e = arr[i]->e;
            pq.push(s);
            sum +=s;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            
            long long ans = (sum*e) ;
            maxi = max(maxi,ans);
        }
        long long mod = (long long) pow(10,9) + (long long) 7;
        long long ret = maxi % mod;
//         return maxi % (int) (1e9 + 7);
        return (int)ret;
    }
    
    static bool func(node* a,node* b)
    {
        return a->e > b->e;
    }
};




