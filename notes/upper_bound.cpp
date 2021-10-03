#include <bits/stdc++.h>
using namespace std;


#### to maintain the sorted order of the stream

int main()
{
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
    

    return 0;
}
