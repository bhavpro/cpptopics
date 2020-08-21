#include <bits/stdc++.h>

using namespace std;

int split(int *trans, int nf)
{
    int noop = 0;
    multiset<int> s;
    for (int i = 0; i < nf; i++)
    {
        if (trans[i] != 0)
            s.insert(trans[i]);
    }

    while (!s.empty())
    {
        noop++;
        auto st = s.begin();
        auto en = prev(s.end());
        int vs = *st;
        int ve = *en;
        s.erase(st);
        s.erase(en);
        int netcred = ve + vs;
        if (netcred != 0)
        {
            s.insert(netcred);
        }
    }
    return noop;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int notr, nof;
    cin >> notr >> nof;
    int *tr = new int[nof];
    memset(tr, 0, sizeof(tr));
    for (int i = 0; i < notr; i++)
    {
        int s, d, t;
        cin >> s >> d >> t;
        tr[s] -= t;
        tr[d] += t;
    }
    cout << split(tr, nof);
    delete[] tr;
    return 0;
}