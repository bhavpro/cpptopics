#include <bits/stdc++.h>

using namespace std;

bool canwemake(unordered_map<int, int> &a)
{
    bitset<3> sqrect;
    sqrect.reset();
    for (pair<int, int> p : a)
    {
        int x = p.second;
        if (sqrect.to_ulong() == 3)
        {
            break;
        }
        if (x >= 8)
        {
            sqrect = 3;
            break;
        }
        if (x >= 6)
        {
            if (sqrect[0] == 1 || sqrect[2] == 1)
            {
                sqrect = 3;
                break;
            }
            else
            {
                sqrect = 5;
                continue;
            }
        }
        if (x >= 4)
        {
            if (sqrect[0] == 1)
            {
                sqrect = 3;
                break;
            }
            else
            {
                sqrect[0] = 1;
                continue;
            }
        }
        if (x >= 2)
        {
            if (sqrect[2] == 1)
            {
                sqrect[1] = 1;
                sqrect[2] = 0;
            }
            else
            {
                if (sqrect[1] == 1)
                {
                    continue;
                }
                else
                {
                    sqrect[2] = 1;
                }
            }
        }
    }
    if (sqrect.to_ulong() == 3)
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
   // freopen("input.txt", "r", stdin);
    int n, q;
    cin >> n;
    unordered_map<int, int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    cin >> q;
    while (q--)
    {
        char ev;
        int addon;
        cin >> ev;
        cin >> addon;
        if (ev == '+')
        {
            a[addon]++;
            n++;
        }
        else
        {
            a[addon]--;
            n--;
        }
        if (n < 8)
        {
            cout << "NO\n";
            continue;
        }
        bool can = canwemake(a);
        if (can)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}