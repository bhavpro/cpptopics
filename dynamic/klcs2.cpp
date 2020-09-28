#include <bits/stdc++.h>

using namespace std;

int klcs(string s1, string s2, int m)
{
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(m + 1, 0)));

    // base

    // rec
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            for (int k = 0; k <= m; k++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j][k] = dp[i - 1][j - 1][k] + 1;
                }

                int x = dp[i - 1][j][k];
                int y = dp[i][j - 1][k];
                dp[i][j][k] = max(max(x, y), dp[i][j][k]);
                if (k != 0)
                {
                    dp[i][j][k] = max(dp[i - 1][j - 1][k - 1], dp[i][j][k]);
                }
            }
        }
    }
    return dp[n1][n2][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int k;
    cin >> k;
    cout << klcs(s1, s2, k);
    return 0;
}