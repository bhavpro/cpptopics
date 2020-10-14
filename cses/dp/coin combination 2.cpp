#include <bits/stdc++.h>

using namespace std;

int ways(vector<int> &coins, int x)
{
    int mod = 1e9 + 7;
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(x + 1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j == 0)
                dp[i][0] = 1;
            else
            {
                dp[i][j] = 0;
                if (j - coins[i] >= 0)
                    dp[i][j] = dp[i][j - coins[i]];
                if (i > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
        }
    }

    return dp[n - 1][x];
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> coin(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    cout << ways(coin, x);
    return 0;
}