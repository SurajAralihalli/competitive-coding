#include <bits/stdc++.h>


using namespace std;

int main()
{
    // set<int,greater<int>> s = {9,4,5,1,-1,7,100}; //descinding order
    // set<int,less<int>> s = {9,4,5,1,-1,7,100}; default 
    
    // MIN HEAP
    set< pair<int,int>,greater<pair<int,int>> > s;
    s.insert(make_pair(1,2));
    s.insert(make_pair(1,3));
    s.insert(make_pair(2,3));
    s.insert(make_pair(1,5));
    
    
    for(auto i:s)
    {
        cout << i.first << " " << i.second << endl;
    }
    
    return 0;
}
