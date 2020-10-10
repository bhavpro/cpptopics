#include <bits/stdc++.h>

using namespace std;

int mctFromLeafValues(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
    for (int k = 0; k < n; k++)
    {
        int j = k;
        for (int i = 0; i < n - k; i++, j++)
        {
            if (i == j)
            {
                dp[i][j] = {0, arr[i]};
            }
            else
            {
                for (int m = i; m < j; m++)
                {
                    pair<int, int> pi, pj, ac1, ac2;
                    pi = dp[i][m];
                    pj = dp[m+1][j];
                    ac1 = {pi.second * pj.second + pi.first + pj.first, max(pi.second, pj.second)};
                    ac2 = dp[i][j];
                    if (ac1.first < ac2.first)
                        dp[i][j] = ac1;
                    else
                        dp[i][j] = ac2;
                }
            }
        }
    }
    return dp[0][n - 1].first;
}