// Author: Suraj Aralihalli
// Url: https://leetcode.com/problems/path-with-maximum-probability/
// Date: 25th September, 2021
// Tags: graph, priority-queue, heap, dijkstra

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> map;
        int k = edges.size();
        for(int i=0;i<k;i++)
        {
            map[edges[i][0]].push_back(make_pair(edges[i][1],succProb[i]));
            map[edges[i][1]].push_back(make_pair(edges[i][0],succProb[i]));
        }
        
        vector<double> reach(n,double(1));
        vector<int> finished(n,0);
        
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        
        pq.push(make_pair(double(0),start));
        reach[start] = double(0);
        
        vector<int> path(n,-1);
        
        while(!pq.empty())
        {
            pair<double,int> node = pq.top();
            pq.pop();
            int v = node.second;
            double f = node.first;
            
            finished[v] =1;
            
            if(map.find(v)==map.end()) continue;
            // cout << "###### parent: " << v << endl;
            vector<pair<int,double>> adj = map[v];
            for(auto i: adj)
            {
                int a = i.first;
                double b = i.second;
                
                // cout << "@@ child: " << a << endl;
                
                if(finished[a]==1) continue;
                
                
                double new_prob = double(1) - ( (double(1) - f)*b);
                if(reach[a]>new_prob)
                {
                    path[a] = v;
                    reach[a] = new_prob;
                    pq.push({reach[a],a});
                }
                
                
            }
        }
        
        
        cout << endl;
        cout << "printing path" << endl;
        int p = path[end];
        cout << end << " ";
        while(p!=-1)
        {
            cout << p << " ";
            p = path[p];
        }
    
            
        return (double(1) - reach[end]);
    }
};


