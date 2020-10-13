#include <bits/stdc++.h>

using namespace std;

int lrs(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (i == j)
                dp[i][j] = dp[i - 1][j];
            else if (s[i - 1] == s[j - 1])
                dp[i][j] = max(dp[i - 1][j - 1] + 1, max(dp[i - 1][j], dp[i][j - 1]));
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][n];
}

int main()
{
    string s;
    cin >> s;
    cout << lrs(s);
    return 0;
}