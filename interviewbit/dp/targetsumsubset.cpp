#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, int B)
{
    int n = A.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(B + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= B; j++)
        {
            if (j == 0)
                dp[i][0] = 1;
            else if (i == 0)
                dp[0][j] = 0;
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (j - A[i - 1] >= 0 && dp[i - 1][j - A[i - 1]])
                    dp[i][j] = 1;
            }
        }
    }
    return dp[n][B];
}
