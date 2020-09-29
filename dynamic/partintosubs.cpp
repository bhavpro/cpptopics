#include <bits/stdc++.h>

using namespace std;

int noss(int n, int k)
{
    vector<vector<int>> dp(k, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
                dp[i][j] = 1;
            else if (j < i)
                dp[i][j] = 0;
            else if (i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] * (i + 1);
        }
    }
    return dp[k - 1][n - 1];
}

int main()
{
    cout << noss(4, 2);
}