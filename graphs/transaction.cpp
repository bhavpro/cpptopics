#include <bits/stdc++.h>

using namespace std;

int arr[10000] = {0};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int p, tt;
    cin >> p >> tt;
    int p1, p2, t;
    for (int i = 0; i < tt; i++)
    {
        cin >> p1 >> p2 >> t;
        arr[p1] -= t;
        arr[p2] += t;
    }

    multiset<pair<int, int>> s;
    for (int i = 0; i < p; i++)
    {
        s.insert(make_pair(arr[i], i));
    }
    while (!s.empty())
    {
        auto l = s.begin();
        auto r = prev(s.end());
        int lp, la, rp, ra;
        la = (*l).first;
        lp = (*l).second;
        ra = (*r).first;
        rp = (*r).second;
        s.erase(l);
        s.erase(r);

        int settle = min(-la, ra);
        la += settle;
        ra -= settle;
        cout << "Person " << lp << " Pays " << settle << " To " << rp << "\n";
        if (la != 0)
        {
            s.insert({la, lp});
        }

        if (ra != 0)
        {
            s.insert({ra, rp});
        }
    }

    return 0;
}