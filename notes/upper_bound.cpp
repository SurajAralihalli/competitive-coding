#include <bits/stdc++.h>
using namespace std;


#### to maintain the sorted order of the stream

int main()
{
    /// VECTOR
    vector<int> vec = {1,2,3,4,5,30,70,300,22222};
    
    int add=56;
    vec.insert(upper_bound(vec.begin(),vec.end(),add),add);
    // auto l = lower_bound(vec.begin(),vec.end(),70); returns iterator to 70
    // auto r = upper_bound(vec.begin(),vec.end(),70); returns iterator to 300
    
    for(auto i:vec)
    {
        cout << i << endl;
    }
    
    // cout << *l << " " << *r << endl;
    
    
    
    /// SET 
    set<int> s = {9,4,5,1,-1,7,100};
    
    int add=6;
    s.insert(6);
    for(auto i:s)
    {
        cout << i << endl;
    }
    // auto l = lower_bound(s.begin(),s.end(),70); returns iterator to 70
    
    auto r = upper_bound(s.begin(),s.end(),70);
    
    
    cout << "upper_bound: " << *r << endl;
    //returns 100

    return 0;

    return 0;
}
