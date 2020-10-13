#include <bits/stdc++.h>

using namespace std;

int isMatch(const string A, const string B)
{

    int m = A.size();
    int n = B.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = 1;
            else if (i == 0)
                dp[0][j] = 0;
            else if (j == 0)
                dp[i][0] = B[i - 1] == '*' ? dp[i - 2][0] : 0;
            else if (B[i - 1] == '*')
                dp[i][j] = ((B[i - 2] != A[j - 1]) && dp[i - 2][j]) || ((B[i - 2] == A[j - 1] || B[i - 2] == '.') && (dp[i][j - 1] | dp[i - 2][j]));
            else if (B[i - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            else if (A[j - 1] == B[i - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
        }
    }
    return dp[n][m];
}