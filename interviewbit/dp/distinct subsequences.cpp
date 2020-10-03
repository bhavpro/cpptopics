#include <bits/stdc++.h>

using namespace std;

int ways(string a, string b, int i, int j)
{
    // base
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    // rec
    int w1 = 0, w2 = 0, w3 = 0;
    if (a[i] == b[j])
        w1 = ways(a, b, i - 1, j - 1);
    w2 = ways(a, b, i - 1, j);
    return w1 + w2;
}

int numDistinct(string A, string B)
{
    return ways(A, B, A.size() - 1, B.size() - 1);
}

int numDistinct(string A, string B)
{
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
                dp[i][j] = 1;
            else if (j == 0)
                dp[i][j] = 0;
            else if (A[j - 1] == B[i - 1] && dp[i - 1][j] > dp[i][j - 1])
                dp[i][j] = dp[i][j - 1] + 1;
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    return dp[n][m];
}