#include <bits/stdc++.h>

using namespace std;

int powmod(long long a, int p, int mod)
{
    long long res = 1;
    while (p > 0)
    {
        if (p & 1)
        {
            res = (res * a) % mod;
        }

        a = ((long long)a * a) % mod;
        p >>= 1;
    }
    return res;
}

int big(int n, int p)
{
    if (p <= n)
    {
        return 0;
    }
    long long num = p - 1;
    long long denom = 1;
    for (int i = n + 1; i < p; i++)
    {
        denom = (denom * i % p) % p;
    }
    denom = powmod(denom, p - 2, p);
    return (denom * num) % p;
}

int main()
{
    int n, p;
    cin >> n >> p;

    cout << big(n, p);
    return 0;
}