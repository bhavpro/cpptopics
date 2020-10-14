#include <bits/stdc++.h>

using namespace std;

int maxpages(int n, int m, vector<int> &price, vector<int> &pages)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (j - price[i - 1] >= 0)
                    dp[i][j] = max(dp[i - 1][j - price[i - 1]] + pages[i - 1], dp[i][j]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> price(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    cout << maxpages(n, m, price, pages);
}