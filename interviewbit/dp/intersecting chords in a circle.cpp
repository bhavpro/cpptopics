#include <bits/stdc++.h>

using namespace std;

int chordCnt(int A)
{
    vector<int> dp(A + 1);
    const int mod = 1e9 + 7;
    long long ans;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= A; i++)
    {
        ans = 0;
        for (int j = 0; j < i; j++)
        {
            ans += dp[j] * dp[i - 1 - j];
            ans %= mod;
        }
        dp[i] = ans;
    }
    return dp[A];
}
