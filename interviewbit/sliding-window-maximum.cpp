// Author: Suraj Aralihalli
// Url: https://www.interviewbit.com/old/problems/sliding-window-maximum/
// Date: 19th September, 2021
// Tags: sliding-window


#include<bits/stdc++.h>
using namespace std;
vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    int i=0;
    int j =0;
    list <int> l;
    vector<int> ans;
    while(j<n)
    {
        int w = j-i+1;
        while(!l.empty() && l.back()<A[j])
        {
            l.pop_back();
        }
        l.push_back(A[j]);

        if(w<B)
        {
            j++;
        }
        else if(w==B)
        {
            
            ans.push_back(l.front());
            
            if(l.front()==A[i])
            {
                l.pop_front();
            }
            
            j++;
            i++;
            
        }
    }
    return ans;
}