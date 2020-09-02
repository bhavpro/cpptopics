#include <bits/stdc++.h>

using namespace std;

#define FIO                          \
    ;                                \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(0);                      \
    cout.tie(0);

#define ll long long

int noat0(int n, ll k)
{
    ll s = 1;
    ll e = 1 << n;
    e--;
    ll mid = (s + e) / 2;
    int ncur = n;
    while (mid != k)
    {
        if (k < mid)
            e = mid - 1;
        else
            s = mid + 1;

        mid = s + e;
        mid >>= 1;
        ncur--;
    }
    return ncur;
}

int noat(int n, ll k)
{
    int ans = 1;
    while (!(k & 1))
    {
        k >>= 1;
        ans++;
    }
    return ans;
}

int main()
{
    FIO;
    ll n, k;
    cin >> n >> k;
    if (k & 1)
        cout << 1;
    else
        cout << noat(n, k);
    return 0;
}