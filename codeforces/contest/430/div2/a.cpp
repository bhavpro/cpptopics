#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;

bool is(int l, int r, int x, int y, int k)
{
    int du = x;
    while (du <= y)
    {
        ld nu = du * k;
        if (nu >= l && nu <= r)
        {
            return true;
        }
        du++;
    }
    return false;
}

int main()
{
    int x, y, l, r;
    ld k;
    cin >> l >> r >> x >> y >> k;
    ld mine, maxe;
    mine = l / y;
    maxe = r / x;
    if (k >= mine && k <= maxe)
        if (is(l, r, x, y, k))
            cout << "YES";
        else
            cout << "NO";
    else
        cout << "NO";

    return 0;
}