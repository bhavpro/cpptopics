#include <bits/stdc++.h>

using namespace std;

int maxg(int cost[][6], int r, int c)
{
    vector<vector<int>> dp(r, vector<int>(c, 0));

    for (int j = 0; j < c; j++)
    {
        for (int i = 0; i < r; i++)
        {
            if (j == 0)
                dp[i][j] = cost[i][j];
            else
            {
                int t1 = (i == 0 ? 0 : dp[i - 1][j - 1]);
                int t2 = (i == r - 1 ? 0 : dp[i + 1][j - 1]);
                int t3 = dp[i][j - 1];
                dp[i][j] = max(t1, max(t2, t3)) + cost[i][j];
            }
        }
    }

    int maxiv = dp[0][c - 1];
    for (int i = 1; i < r; i++)
    {
        maxiv = max(maxiv, dp[i][c - 1]);
    }
    return maxiv;
}

int main()
{
    int arr[6][6] = {{0, 1, 4, 2, 8, 2},
                     {4, 3, 6, 5, 0, 4},
                     {1, 2, 4, 1, 4, 6},
                     {2, 0, 7, 3, 2, 2},
                     {3, 1, 5, 9, 2, 4},
                     {2, 7, 0, 8, 5, 1}};

    int m = 6, n = 6;

    cout << maxg(arr, m, n);
}