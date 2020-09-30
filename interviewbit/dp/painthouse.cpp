#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &A)
{
    int n = A.size();
    vector<vector<int>> dp(3, vector<int>(n));
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (j == 0)
                dp[i][0] = A[0][i];
            else
            {
                dp[i][j] = A[j][i] + min(dp[(i + 1) % 3][j - 1], dp[(i + 2) % 3][j - 1]);
            }
        }
    }
    return min(dp[0][n - 1], min(dp[1][n - 1], dp[2][n - 1]));
}
