#include <bits/stdc++.h>

using namespace std;

string reverseString(string A)
{
    stack<char> c;
    string ans;
    for (char x : A)
        c.push(x);

    while (!c.empty())
    {
        ans += c.top();
        c.pop();
    }
    return ans;
}
