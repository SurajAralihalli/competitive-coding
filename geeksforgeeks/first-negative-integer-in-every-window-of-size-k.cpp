// Author: Suraj Aralihalli
// Url: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
// Date: 18th September, 2021
// Tags: sliding-window

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                     
                     vector<long long> ans;
                     int i =0;
                     int j =0;
                     int n=0;
                     queue<long long> q;
                     while(j<N)
                     {
                        //  cout << i << " " << j << endl;
                         int w = j-i+1;
                         if(w<K)
                         {
                             if(A[j]<0) q.push(A[j]);
                             j++;
                             
                         }
                         else if(w==K)
                         {
                             if(A[j]<0) q.push(A[j]);
                             j++;
                             
                             if(q.size()==0)
                             {
                                 ans.push_back((long long)0);
                             }
                             else
                             {
                                 ans.push_back(q.front());
                             }
                             
                             if(q.front()==A[i])
                             {
                                 q.pop();
                             }
                             i++;
                         }
                         
                     }
                     return ans;
 }
