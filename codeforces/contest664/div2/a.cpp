#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool checkp(ll r, ll g, ll b, ll w)
{
    int nod = 0;
    nod = (r & 1) + (b & 1) + (g & 1);
    if (w & 1)
    {
        if (nod != 1)
        {
            return true;
        }
    }
    else
    {
        if (nod != 2)
            return true;
    }
    return false;
}

int main()
{
   //  freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        ll r, g, b, w;
        cin >> r >> g >> b >> w;
        if (r == 0 || g == 0 || b == 0)
        {
            if ((r & 1) + (g & 1) + (b & 1) + (w & 1) > 1)
            {
                cout << "No \n";
            }
            else
            {
                cout << "Yes \n";
            }
            continue;
        }

        if (checkp(r, g, b, w))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}