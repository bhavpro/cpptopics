#include <bits/stdc++.h>

using namespace std;

int maxp(vector<int> loot)
{
    int n = loot.size();
    vector<int> dp(n);
    dp[0] = loot[0];
    dp[1] = max(loot[0], loot[1]);
    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + loot[i]);

    return dp[n - 1];
}