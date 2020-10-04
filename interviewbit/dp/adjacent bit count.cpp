#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define vcpi vector<pii>

int abc(int n, int k)
{
    vector<vcpi> dp(k + 1, vcpi(n + 1));

    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j == 0)
                dp[i][j] = {0, 0};
            else if (i == 0)
                if (j == 1)
                    dp[0][1] = {1, 1};
                else
                    dp[0][j] = {dp[0][j - 1].first + dp[0][j - 1].second, dp[0][j - 1].first};
            else
            {
                dp[i][j].first = dp[i][j - 1].first + dp[i][j - 1].second;
                dp[i][j].second = dp[i][j - 1].first + dp[i - 1][j - 1].second;
            }
        }
    }
    return dp[k][n].first + dp[k][n].second;
}

int main()
{
    int t;
    cin >> t;
    int num, n, k;
    while (t--)
    {
        cin >> num >> n >> k;
        cout << num << " " << abc(n, k) << "\n";
    }
    return 0;
}