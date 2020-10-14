#include <bits/stdc++.h>

using namespace std;

int ways(vector<int> &coins, int x)
{
    int mod = 1e9 + 7;
    int n = coins.size();
    vector<int> dp(x + 1);

    for (int i = 0; i <= x; i++)
    {
        if (i == 0)
            dp[0] = 1;
        else
        {
            dp[i] = 0;
            for (int j = 0; j < n; j++)
                if (i - coins[j] >= 0)
                    dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
        }
    }
    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
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