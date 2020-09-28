#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &a)
{
    int noc = a[0].size();
    int noh = a.size();
    vector<vector<int>> dp(noc, vector<int>(noh));
    for (int j = 0; j < noh; j++)
    {
        for (int i = 0; i < noc; i++)
        {
            if (j == 0)
            {
                dp[i][0] = a[0][i];
            }
            else
            {
                int minval = INT_MAX;
                for (int k = 0; k < noc; k++)
                {
                    if (k != i)
                    {
                        minval = min(minval, dp[k][j - 1]);
                    }
                }
                dp[i][j] = minval + a[j][i];
            }
        }
    }

    int minval = dp[0][noh - 1];
    for (int i = 1; i < noc; i++)
        minval = min(minval, dp[i][noh - 1]);
    return minval;
}

int main()
{
    vector<vector<int>> a;
    a.push_back({1, 5, 7, 2, 1, 4});
    a.push_back({5, 8, 4, 3, 6, 1});
    a.push_back({3, 2, 9, 7, 2, 3});
    a.push_back({1, 2, 4, 9, 1, 7});
    cout << solve(a);
}