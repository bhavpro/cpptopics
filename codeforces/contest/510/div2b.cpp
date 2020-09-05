#include <bits/stdc++.h>

using namespace std;

#define min4(a, b, c, d) min(min(a, b), min(c, d));

int Max = 1e6;

int solve(unordered_map<string, int> m)
{
    m["AB"] = min(m["A"] + m["B"], m["AB"]);
    m["BC"] = min(m["B"] + m["C"], m["BC"]);
    m["AC"] = min(m["A"] + m["C"], m["AC"]);
    m["ABC"] = min4(m["ABC"], m["A"] + m["BC"], m["AB"] + m["C"], m["AC"] + m["B"]);
    m["ABC"] = min4(m["ABC"], m["AB"] + m["BC"], m["AC"] + m["AB"], m["AC"] + m["BC"]);
    if (m["ABC"] == Max)
        return -1;
    return m["ABC"];
}

int main()
{

    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    unordered_map<string, int> m;
    m["A"] = Max;
    m["B"] = Max;
    m["C"] = Max;
    m["AB"] = Max;
    m["BC"] = Max;
    m["AC"] = Max;
    m["ABC"] = Max;

    while (n--)
    {
        int x;
        string str;
        cin >> x >> str;
        sort(str.begin(), str.end());
        m[str] = min(m[str], x);
    }

    cout << solve(m) << "\n";

    return 0;
}