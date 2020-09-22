#include <bits/stdc++.h>

using namespace std;

int minPathSum(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = A[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = dp[i][j - 1] + A[i][j];
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] + A[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + A[i][j];
            }
        }
    }
    return dp[m - 1][n - 1];
}