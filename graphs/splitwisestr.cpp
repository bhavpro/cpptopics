#include <bits/stdc++.h>

using namespace std;

struct spsi
{
    bool operator()(const pair<string, int> &a, const pair<string, int> &b)
    {
        if (a.second <= b.second)
            return true;
        return false;
    }
};

int split(unordered_map<string, int> m)
{
    int noop = 0;
    multiset<pair<string, int>, spsi> s;
    for (pair<string, int> p : m)
    {
        if (p.second != 0)
            s.insert({p.first, p.second});
    }

    while (!s.empty())
    {
        noop++;
        auto st = s.begin();
        auto en = prev(s.end());
        auto vs = *st;
        auto ve = *en;
        s.erase(st);
        s.erase(en);
        int netcred = ve.second + vs.second;
        cout << vs.first << " will give " << min(abs(vs.second), ve.second) << " amount to " << ve.first << "\n";
        string str = "";
        if (netcred < 0)
        {
            str = vs.first;
        }
        else
        {
            str = ve.first;
        }
        if (netcred != 0)
        {
            s.insert({str, netcred});
        }
    }
    return noop;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int notr, nof;
    cin >> notr >> nof;
    unordered_map<string, int> m;
    for (int i = 0; i < notr; i++)
    {
        string s, d;
        int t;
        cin >> s >> d >> t;
        m[s] -= t;
        m[d] += t;
    }
    cout << split(m);
    return 0;
}