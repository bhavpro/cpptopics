#include <bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
            dp[i] = 0;
        else
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
    }
    return dp[n - 1];
}