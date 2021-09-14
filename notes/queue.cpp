#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << q.front() << endl;
    cout << q.back() << endl;


    q.pop();
    cout << q.front() << endl;

    q.empty(); //true if empty

}