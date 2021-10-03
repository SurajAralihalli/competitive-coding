#include <bits/stdc++.h>
using namespace std;


int main()
{
    set<pair<int,int>> s;
    
    for(int i=0;i<10;i++)
    {
        s.insert({i,i+1});
    }
    
    s.insert({1,2});
    cout << s.count({1,2}) << endl;
    
    cout << s.count({99,2}) << endl;
    
    s.erase(s.find({1,2}));
    cout << s.count({1,2}) << endl;
    
    // s.erase(s.find({99,2})); Error
    // cout << s.count({99,2}) << endl;
    
    if(s.find({99,2})==s.end())
    {
        cout << "not found" << endl;
    }
    
    if(find(s.begin(),s.end(),make_pair(1,2))==s.end())
    {
        cout << "not found" << endl;
    }
    
    vector<int> v = {1,2,3,3,3,3,3,4,5};
    
    set <int> r(v.begin(),v.end());
    for(auto i: r)
    {
        cout << "r: " << i <<  endl;
    }

    return 0;
}
