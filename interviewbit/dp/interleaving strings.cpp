#include <bits/stdc++.h>

using namespace std;

int isInterleave(string A, string B, string C)
{
    int n = A.size();
    int m = B.size();
    int z = C.size();
    int k = 0;

    if (n + m != z)
        return false;

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            k = i + j;
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = B[j - 1] == C[k - 1] ? dp[0][j - 1] : 0;
            else if (j == 0)
                dp[i][j] = A[i - 1] == C[k - 1] ? dp[i - 1][0] : 0;
            else if (A[i - 1] == C[k - 1] && B[j - 1] == C[k - 1])
                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
            else if (A[i - 1] == C[k - 1])
                dp[i][j] = dp[i - 1][j];
            else if (B[j - 1] == C[k - 1])
                dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[n][m];
}
