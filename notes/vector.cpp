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

    cout << "SAMPLE" << endl;
    vector<int> sample = {1,2,3,4,5,6};
    
    cout << sample.front() << endl;
    cout << sample.back() << endl;
    sample.insert(sample.begin()+1,0);
    cout << sample[1] << endl;


    vector<int> bec = { 10, 20, 30, 40, 89,78, 59,60 };
    int i = 2;
    // inserts 7 at i-th index
    bec.insert(bec.begin() + i, 7);
    
    
    // erase one element
    bec.erase (myvector.begin()+5);

    // erase the first 3 elements:
    bec.erase (myvector.begin(),myvector.begin()+3);


}
