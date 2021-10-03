#include<bits/stdc++.h>
using namespace std;



void showlist(list <int> g)
{
    
    for(auto it = g.begin(); it != g.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
  
int main()
{
  
    list <int> l1, l2;
  
  
    for (int i = 0; i < 10; ++i)
    {
        l1.push_back(i * 2);
        l2.push_front(i * 3);
    }
    cout << "List 1 (l1) is : " << endl;
    showlist(l1);
  
    cout << "List 2 (l2) is : " << endl;
    showlist(l2);
  
    cout << "l1.front() : " << l1.front() << endl;
    cout << "l1.back() : " << l1.back() << endl;
  
    cout << "l1.pop_front() : ";
    l1.pop_front();
    showlist(l1);
  
    cout << "l2.pop_back() : ";
    l2.pop_back();
    showlist(l2);
  
    cout << "l1.reverse() : ";
    l1.reverse();
    showlist(l1);
  
    cout << "l2.sort(): ";
    l2.sort();
    showlist(l2);
    
    
    
    
    vector<int> v = {1,2,3,3,3,3,3,4,5};
    
    list<int> l(v.begin(),v.end());
    for(auto i: l)
    {
        cout << "l: " << i <<  endl;
    }
    
    l.erase(find(l.begin(),l.end(),3));
    for(auto i: l)
    {
        cout << "new l: " << i <<  endl;
    }
  
    return 0;
  
}
