#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack <int> stk;

    cout << stk.size() << endl;

    stk.push(1);
    stk.push(2);
    cout << "is stack empty "<< stk.empty() << endl;
    cout << stk.top() << endl;

    stk.pop();
    cout << stk.top() << endl;
    stk.push(3);
    stk.push(4);
    cout << stk.size() << endl;

    return 0;
}