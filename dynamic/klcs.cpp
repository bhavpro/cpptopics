#include <iostream>
#include <string>

using namespace std;

int memo[20][20][20];

int klcs(string a, string b, int k, int i = 0, int j = 0)
{
    // base
    if (i == a.length() || j == b.length())
    {
        memo[i][j][k] = 0;
        return 0;
    }

    // rec
    if (a[i] == b[j])
    {
        return 1 + (memo[i + 1][j + 1][k] == -1 ? klcs(a, b, k, i + 1, j + 1) : memo[i + 1][j + 1][k]);
    }

    int x = memo[i + 1][j][k] == -1 ? klcs(a, b, k, i + 1, j) : memo[i + 1][j][k];
    int y = memo[i][j + 1][k] == -1 ? klcs(a, b, k, i, j + 1) : memo[i][j + 1][k];
    int z = 0;
    if (k != 0)
    {
        z = memo[i + 1][j + 1][k - 1] == -1 ? klcs(a, b, k - 1, i + 1, j + 1) + 1 : memo[i + 1][j + 1][k - 1];
    }
    return max(z, max(x, y));
}

int klcsdp(string a, string b, int m)
{
    // base
    int dp[20][20][20];

    // rec
    for (int i = 0; i <= a.length(); i++)
    {
        for (int j = 0; j <= b.length(); j++)
        {
            for (int k = 0; k <= m; k++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j][k] = 0;
                    continue;
                }

                if (a[i - 1] == b[j - 1])
                {
                    dp[i][j][k] = dp[i - 1][j - 1][k] + 1;
                    continue;
                }

                int x = dp[i - 1][j][k];
                int y = dp[i][j - 1][k];
                dp[i][j][k] = max(x, y);
                if (k != 0)
                {
                    dp[i][j][k] = max(dp[i - 1][j - 1][k - 1] + 1, dp[i][j][k]);
                }
            }
        }
    }
    return dp[a.length()][b.length()][m];
}

int main()
{
    string a, b;
    cin >> a >> b;
    int k;
    cin >> k;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            for (int k = 0; k < 20; k++)
            {
                memo[i][j][k] = -1;
            }
        }
    }
    cout << klcs(a, b, k);
    cout << "\n"
         << klcsdp(a, b, k);
    return 0;
}