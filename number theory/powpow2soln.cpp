#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int mod = 1000000007;

int powmod(int a, int power, int mod)
{
    // base
    if (power == 0)
    {
        return 1 % mod;
    }
    if (power == 1)
    {
        return a % mod;
    }

    // rec
    ll ans = powmod(a, power >> 1, mod);
    ans = (ans * ans) % mod;
    if (power & 1 == 1)
        ans = (ans * a) % mod;
    return ans;
}

int multmodinv(int n, int mod)
{
    for (int i = 1; i < mod; i++)
    {
        if (((ll)n * i) % mod == 1)
        {
            return i;
        }
    }
    return -1;
}

int modfor2ncn(int n, int mod)
{
    // for numer
    ll num = 1;
    for (ll i = (ll)2 * n; i > n; i--)
    {
        num = (num * i) % mod;
    }

    // for denom
    // mod is prime
    ll denom = 1;
    if (mod == 2 || mod == 148721)
    {
        denom = powmod(n, mod - 2, mod);
        return (num * denom) % mod;
    }

    // else mod not prime
    for (int i = 2; i < n; i++)
    {
        denom = (multmodinv(i, mod) * denom) % mod;
    }
    return (num * denom) % mod;
}

int inverse(int x, int mod)
{
    if (mod == 2 || mod == 148721 || mod == 500000003)
    {
        if (mod == 2)
        {
            return 1;
        }
        return powmod(x, mod - 2, mod);
    }
    return multmodinv(x, mod);
}

int crt(int *div, int *rem, int n)
{
    ll ans = 0;
    ll prod = 1;
    ll localans;
    for (int i = 0; i < n; i++)
    {
        prod *= div[i];
    }
    for (int i = 0; i < n; i++)
    {
        int ppi = prod / div[i];
        localans = ((rem[i] * ppi) % prod * (inverse(ppi, div[i]) % prod)) % prod;
        ans = (ans + localans) % prod;
    }
    return ans;
}

int powpow2(int a, int b, int n)
{
    int mod2ncn[3];
    int div2ncn[3] = {2, 41 * 41, 148721};
    for (int i = 0; i < 3; i++)
    {
        mod2ncn[i] = modfor2ncn(n, div2ncn[i]);
    }
    int modforp2 = crt(div2ncn, mod2ncn, 3);
    int modb[] = {(b % 2 == 0 ? 0 : 1), modforp2};
    int divb[] = {2, 500000003};
    int modforb = crt(divb, modb, 2);
    return powmod(a, modforb, ::mod);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int a, b, n, t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> n;
        cout << powpow2(a, b, n);
    }

    return 0;
}