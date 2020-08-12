#include <bits/stdc++.h>

using namespace std;

#define max4(a, b, c, d) max(max(a, b), max(c, d))

int dp(string &a, string &b, int k)
{
    vector<vector<vector<int>>> dp(a.size() + 1, vector<vector<int>>(b.size() + 1, vector<int>(k + 1)));
    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            for (int m = 0; m <= k; m++)
            {
                if (i == 0)
                {
                    dp[i][j][m] = 0;
                    continue;
                }
                if (j == 0)
                {
                    dp[i][j][m] = 0;
                    continue;
                }
                dp[i][j][m] = dp[i - 1][j - 1][m];
                if (a[i - 1] == b[j - 1])
                    dp[i][j][m] = max(dp[i][j][m], dp[i - 1][j - 1][m] + 1);
                dp[i][j][m] = max4(dp[i][j][m], dp[i][j][m - 1] + 1, dp[i][j - 1][m], dp[i - 1][j][m]);
            }
        }
    }
    return dp[a.size()][b.size()][k];
}

int main()
{
    string a, b;
    int k;
    cin >> a >> b;
    cin >> k;
    cout << dp(a, b, k);
    return 0;
}