#include <bits/stdc++.h>

using namespace std;

int dp(string &a, string &b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            if (i == 0)
            {
                dp[0][j] = j;
                continue;
            }
            if (j == 0)
            {
                dp[i][0] = i;
                continue;
            }

            dp[i][j] = INT_MAX;
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]); // same char
            }
            else
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1); // replace
            }

            // ins
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);

            // del
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        }
    }
    return dp[a.size()][b.size()];
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << dp(a, b);
    return 0;
}