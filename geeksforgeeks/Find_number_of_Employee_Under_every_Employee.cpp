// Author: Suraj Aralihalli
// Url: https://www.geeksforgeeks.org/find-number-of-employees-under-every-manager/
// Date: 19th July, 2021
// Tags: toposort, dfs, reverse

#include <bits/stdc++.h>
using namespace std;


void topo_visit(int i, vector<int>& order, vector<int>& visited, unordered_map<int,int>& map)
{
    visited[i]=1;
    
    int next = map[i];
    if(visited[next]==0)
    {
        topo_visit(next, order, visited, map);
    }

    order.push_back(i);
}

int main()
{
    unordered_map<int,int> map;

    //input1
    // map[0] = 2;
    // map[1] = 2;
    // map[2] = 5;
    // map[3] = 4;
    // map[4] = 5;
    // map[5] = 5; 
    
    //input2
    map[1] = 0;
    map[5] = 7;
    map[2] = 5;
    map[3] = 4;
    map[4] = 5;
    map[6] = 0;
    map[0] = 2;
    map[7] = 7;
    

    int n = map.size();
    vector<int> visited(n,0);
    vector<int> order;

    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            topo_visit(i, order, visited, map);
        }
    }

    reverse(order.begin(), order.end());
    vector<int> count(n,0);
    
    
    for(auto i: order)
    {
        cout << i << " ";
        int next = map[i];
        if(i!=next)
        {
            count[next] += count[i] + 1;
        }
    }
    cout << endl;
    cout << "printing answer below" << endl;
    for(int i=0;i<n;i++)
    {
        cout << i << " " << count[i] << endl;
    }

    return 0;
}
