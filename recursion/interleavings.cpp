#include <iostream>
#include <string>
using namespace std;

void rec(string s, string t, int x, int y, string str = "")
{
    cout << "\n";
    if (x == s.size() && y == t.size())
    {
        cout << str;
        return;
    }

    if (x == s.size())
    {
        cout << str << t.substr(y, t.size() - y);
        return;
    }

    if (y == t.size())
    {
        cout << str << s.substr(x, t.size() - x);
        return;
    }

    // rec
    rec(s, t, x + 1, y, str + s[x]);
    rec(s, t, x, y + 1, str + t[y]);
}

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    rec(s, t, 0, 0);
    return 0;
}