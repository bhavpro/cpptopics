#include <bits/stdc++.h>

using namespace std;

int maxval(vector<int> w, vector<int> p, int n, int tw)
{
    vector<vector<int>> dp(n + 1, vector<int>(tw + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= tw; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (j - w[i - 1] >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + p[i - 1]);
            }
        }
    }
    return dp[n][tw];
}

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> price(n);
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> price[i];
    }

    cout << maxval(weight, price, n, w);
    return 0;
}