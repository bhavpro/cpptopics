#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int cap = *max_element(A.begin(), A.end());
    int n = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1));
    int basecost = C[find(B.begin(), B.end(), 1) - B.begin()];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= cap; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = 0;
            else if (i == 0)
                dp[0][j] = dp[0][j - 1] + basecost;
            else if (j == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (j - B[i - 1] >= 0)
                    dp[i][j] = min(dp[i][j], C[i - 1] + min(dp[i][j - B[i - 1]], dp[i - 1][j - B[i - 1]]));
            }
        }
    }

    int sum = 0;
    for (int x : A)
        sum += dp[n][x];
    return sum;
}

int solveop(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int cap = *max_element(A.begin(), A.end());
    int n = B.size();
    vector<int> dp(cap + 1, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int dc = B[i];
        for (int j = dc; j <= cap; j++)
        {
            dp[j] = min(dp[j], dp[j - B[i]] + C[i]);
        }
    }

    int sum = 0;
    for (int x : A)
        sum += dp[x];
    return sum;
}