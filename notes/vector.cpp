#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> vec;
    vec.assign(10,10);
    string s = "suraj";
    for(int i =0;i<s.size();i++)
    {
        vec[i] = i;
    }
    cout << "###########" << endl;

    for(auto &i : vec)
    {
        cout << i << endl;
        i = 9;
    }

    for(auto i : vec)
    {
        cout << i << endl;
    }

    cout << "&&&&&&&&&&&&&" << endl;


    for(auto i = vec.begin();i!=vec.end();i++)
    {
        cout << *i << endl;
    }

    cout << "@@@@@@@@@@@@@@@@" << endl;
    cout << (find(vec.begin(),vec.end(),1)!=vec.end()) << endl;
}