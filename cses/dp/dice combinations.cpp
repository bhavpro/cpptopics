#include <bits/stdc++.h>

using namespace std;

int ways(int n)
{
    int mod = 1e9 + 7;
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            dp[0] = 1;
        else
        {
            dp[i] = 0;
            for (int j = 1; j <= min(6, i); j++)
                dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << ways(n);
}