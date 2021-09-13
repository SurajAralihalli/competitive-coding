#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    string s = "1;2;3;4;5;6;";
    
    stringstream ss(s);
    
    string token;
    while(getline(ss,token,';'))
    {
        cout << token << endl;
    }
}