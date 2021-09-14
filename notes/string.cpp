#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "abcd";
    s1.erase(0,1);
    cout << s1 << endl;

    s1 = "abcdefghijklmnop";
    s1.erase(7);
    cout << s1 << endl;


    string s2 = "efgh";
    string s3;
    s3.assign(s2.begin()+4,s2.end());
    cout << s3.size() << endl;

    string s4(3,'y');
    cout << s4 << endl;

    string s5 = "abcdefghijklmnop";
    cout << s5.substr(1,4) << endl;
    cout << s5.substr(1) << endl;


    string a = "12345";
    
    vector<int> vec = {1,2,3,4,5,6,7};
    
    int w = int(a.end()==find(a.begin(),a.end(),'2'));
    
    a.find("34");
    cout << int(a.npos == a.find("@@")) << endl; // else returns index
    
    string c = a.substr(0,2);
    
    cout << c << endl;
    
    int e = stoi(a);
    cout << e << endl;
    
    cout << to_string(e) << endl;
    return 0;
}