#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char,int> hash;
    string s = "suraj";
    for(int i =0;i<s.size();i++)
    {
        hash[s[i]]=i+100;
    }
    for(auto i : hash)
    {
        cout << i.first << " " << i.second << endl;
    }

    for(auto i = hash.begin();i!=hash.end();i++)
    {
        cout << i->first << " " << i->second << endl;
    }

    cout << "@@@@@@@@@@@@@@@@" << endl;
    cout << (hash.find('s')!=hash.end()) << endl;
}