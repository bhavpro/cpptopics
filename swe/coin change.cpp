#include <bits/stdc++.h>

using namespace std;

int leastCoins(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - coins[j]]);
            }
        }
        if (dp[i] == INT_MAX)
        {
            return -1;
        }
        dp[i]++;
    }
    return dp[amount];
}