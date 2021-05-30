#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout << "MAX HEAP" << endl;
    // max heap
    priority_queue<pair<int,vector<int>>> pq;
    // priority_queue<int> pq;
    vector <int> vec = {1,2,3};
    pq.push({1,vec});
    vec.pop_back();
    vec.push_back(4);
    pq.push({2,vec});

    cout<< pq.top().first << endl;
    cout<< pq.top().second[2] << endl;
    pq.pop();
    cout<< pq.top().first << endl;
    cout<< pq.top().second[2] << endl;

    cout << "MIN HEAP" << endl;
    //min heap
    priority_queue<int,vector<int>,greater<int>> pq2;
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq3;
    pq2.push(10);
    pq2.push(7);
    pq2.push(8);
    pq2.push(200);
    pq2.push(1111);
    pq2.push(1);
    pq2.push(-100);
    pq2.push(5);
    pq2.push(12333);

    cout << "TOP " << "SIZE OF HEAP" << endl;
    while(!pq2.empty())
    {
        cout << pq2.top() << " " << pq2.size() << endl;
        pq2.pop();
    }
    return 0;
}
