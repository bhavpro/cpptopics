#include <bits/stdc++.h>

using namespace std;

bool isdup(string a)
{
    stack<char> s;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != ')')
            s.push(a[i]);
        else
        {
            if (s.top() == '(')
                return true;
            while (s.top() != '(')
                s.pop();
            s.pop();
        }
    }
    return false;
}

int main()
{
    string a;
    cin >> a;
    cout << (isdup(a) == 1 ? "true" : "false");
    return 0;
}