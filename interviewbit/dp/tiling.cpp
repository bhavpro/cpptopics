#include <bits/stdc++.h>

using namespace std;

int solve(int A)
{
    if (A & 1)
        return 0;
    const int mod = 1e9 + 7;
    long long ans = 1;
    for (int i = 1; i <= (A >> 1); i++)
    {
        ans = (ans * 3 + 2) % mod;
    }
    return ans;
}
