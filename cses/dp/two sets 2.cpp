#include <bits/stdc++.h>

using namespace std;

int noset(int n, int sum)
{
#define ll long long
    int mod = 1e9 + 7;
    vector<vector<ll>> dp(n + 1, vector<ll>(sum + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][0] = 1;
            else if (i == 0)
                dp[0][j] = 0;
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (j - i >= 0)
                    dp[i][j] = (dp[i][j] + 0LL + dp[i - 1][j - i]) % (2 * mod);
            }
        }
    }

    return (dp[n][sum] >> 1) % mod;
}

int main()
{
    int n;
    cin >> n;
    int sum = n * (n + 1);
    sum >>= 1;
    if (sum & 1)
        cout << 0;
    else
    {
        cout << noset(n, sum >> 1);
    }
    return 0;
}