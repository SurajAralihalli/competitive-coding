#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "abcd";
    s1.erase(0,1);
    cout << s1 << endl;

    string s2 = "efgh";
    string s3;
    s3.assign(s2.begin()+4,s2.end());
    cout << s3.size() << endl;

    string s4(3,'y');
    cout << s4 << endl;
    return 0;
}