#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> queenAttack(vector<string> &A)
{
    int m = A.size();
    int n = A[0].size();
    int d = (max(m, n) << 1) - 1;
    int inc = max(m, n) - 1;

    vector<int> row(m, 0), col(n, 0), d1(d, 0), d2(d, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == '1')
            {
                row[i] = 1;
                col[j] = 1;
                d1[inc + j - i] = 1;
                d2[i + j] = 1;
            }
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = row[i] + col[j] + d1[inc + j - i] + d2[i + j];
            if (A[i][j] == '1' && dp[i][j] > 0)
                dp[i][j] -= 4;
        }
    }

    return dp;
}
