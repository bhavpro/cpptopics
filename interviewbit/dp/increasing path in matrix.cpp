#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<bool>> dp(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = 1;
            else
            {
                dp[i][j] = 0;
                if (i != 0 && A[i][j] > A[i - 1][j])
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                if (j != 0 && A[i][j] > A[i][j - 1])
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
    }
    return dp[n][m] ? n + m - 1 : -1;
}
