#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {1, 2, 3, 3};
    int n = 4;
    int sum = 6;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][0] = 1;
            else if (i == 0)
                dp[0][j] = 0;
            else
            {
                dp[i][j] = dp[i - 1][j];
                int remsum = j - a[i - 1];
                if (remsum >= 0)
                    dp[i][j] += dp[i - 1][remsum];
            }
        }
    }

    cout << dp[n][sum];

    return 0;
}