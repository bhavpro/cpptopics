#include <bits/stdc++.h>

using namespace std;

int solve(string A)
{
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int j = 0; j < n; j++)
    {
        int k = j;
        for (int i = 0; i < n - j; i++, k++)
        {
            if (i == k)
                dp[i][k] = 1;
            else if (A[i] == A[k])
                dp[i][k] = 2 + dp[i + 1][k - 1];
            else
                dp[i][k] = max(dp[i + 1][k], dp[i][k - 1]);
        }
    }
    return dp[0][n - 1];
}
