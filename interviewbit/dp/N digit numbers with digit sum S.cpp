#include <bits/stdc++.h>

using namespace std;

int solve(int A, int B)
{
    int mod = 1e9 + 7;
    int N = A;
    int S = B;
    vector<vector<int>> dp(N + 1, vector<int>(S + 1));
    for (int i = 0; i < N + 1; i++)
    {
        for (int j = 0; j < S + 1; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = 0;
                for (int k = 1; k <= min(9, j); k++)
                {
                    if (j - k >= 0)
                        dp[i][j] = (dp[i][j] + 0LL + dp[i - 1][j - k]) % mod;
                }
                if (S != j)
                    dp[i][j] = (dp[i][j] + 0LL + dp[i - 1][j]) % mod;
            }
        }
    }
    return dp[N][S];
}
