#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, vector<int> &B, int C)
{
    int n = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (j >= B[i - 1])
                dp[i][j] = A[i - 1] + dp[i - 1][j - B[i - 1]];
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    return dp[n][C];
}
