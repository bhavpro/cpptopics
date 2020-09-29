#include <bits/stdc++.h>

using namespace std;

int power(int a, int p, int mod)
{
    int res = 1;
    a %= mod;
    while (p > 0)
    {
        if (p & 1)
        {
            res = (a * res) % mod;
        }
        p >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

int main()
{
    cout << power(2, 5, 7);
    return 0;
}