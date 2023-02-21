// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/network-delay-time/
// Date: 28th August, 2021
// Tags: dp, dijkstra, graph


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector< vector<int> > mat;
        mat.assign(n,vector<int> (n,-1));
        vector<int> reached(n,0);
        vector<int> dist(n, INT_MAX);

        for(auto i:times)
        {
            mat[i[0]-1][i[1]-1]=i[2];
        }
        
        k = k-1;
        dist[k]=0;
        reached[k]=1;
        while(true)
        {
            int next =-1;
            int next_dist = INT_MAX;
            for(int i=0;i<n;i++)
            {
                        

                if(mat[k][i]!=-1 && reached[i]==0)
                {
                    if(mat[k][i]+dist[k] < dist[i])
                    {
                        dist[i] = mat[k][i]+dist[k];
                    }
                    
                    next_dist = min(next_dist,dist[i]);
                    if(dist[i]==next_dist)
                    {
                        next = i;

                    }
                }
            }
            
            if(next==-1) break;
            
            k = next;
            reached[k] = 1;
        }
        for(int j : dist)
        {
            cout << j << " ";
        }
        
        int t = *max_element(dist.begin(),dist.end());
        return t==INT_MAX?-1:t;
            
    }
};
