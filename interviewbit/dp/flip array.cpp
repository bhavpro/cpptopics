#include <bits/stdc++.h>

using namespace std;

int memo[1005][1005];

pair<int, int> rec(const vector<int> &a, int i, int sum, int flips = 0)
{
    // base
    if (i == a.size())
        return sum < 0 ? make_pair(INT_MAX, flips) : make_pair(sum, flips);
    // rec
    return min(rec(a, i + 1, sum + a[i], flips), rec(a, i + 1, sum - a[i], flips + 1));
}

int solve(const vector<int> &A)
{
    return rec(A, 0, 0, 0).second;
}

int solvedp(const vector<int> &A)
{
    int n = A.size();
    int nof = n >> 1;
    nof++;
    vector<vector<int>> dp(n + 1, vector<int>(nof + 1));
    int minval = 1e9;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= nof; j++)
        {
            if (i == 0)
                dp[0][j] = 0;
            else if (j == 0)
                dp[i][0] = dp[i - 1][0] + A[i - 1];
            else
                dp[i][j] = min(dp[i - 1][j] + A[i - 1], dp[i - 1][j - 1] - A[i - 1]);

            if (i == n)
                minval = min(minval, (dp[i][j] < 0 ? (int)1e9 : dp[i][j]));
        }
    }
    return minval;
}
