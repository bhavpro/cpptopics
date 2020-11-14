#include <bits/stdc++.h>

using namespace std;

int maxcoin(vector<int> &A)
{
    int n = A.size();
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
    bool fp = (n & 1 ? true : false);
    for (int k = 0; k < n; k++)
    {
        for (int j = k, i = 0; i < n - k; i++, j++)
        {
            if (fp)
            {
                if (i == j)
                    dp[i][j] = {A[i], 0};
                else
                {
                    pair<int, int> x, y;
                    x = {A[i] + dp[i + 1][j].first, dp[i + 1][j].second};
                    y = {A[j] + dp[i][j - 1].first, dp[i][j - 1].second};
                    if (x.first > y.first)
                        dp[i][j] = x;
                    else if (y.first > x.first)
                        dp[i][j] = y;
                    else
                        dp[i][j] = (x.second < y.second ? x : y);
                }
            }
            else
            {
                if (i == j)
                    dp[i][j] = {0, A[i]};
                else
                {
                    pair<int, int> x, y;
                    x = {dp[i + 1][j].first, A[i] + dp[i + 1][j].second};
                    y = {dp[i][j - 1].first, A[j] + dp[i][j - 1].second};
                    if (x.second > y.second)
                        dp[i][j] = x;
                    else if (y.second > x.second)
                        dp[i][j] = y;
                    else
                        dp[i][j] = (x.first < y.first ? x : y);
                }
            }
        }
        fp = !fp;
    }
    return dp[0][n - 1].first;
}
