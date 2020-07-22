#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    // base

    // rec
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = (s1[i - 1] == s2[j - 1] ? max(dp[i][j], dp[i - 1][j - 1] + 1) : dp[i][j]);
        }
    }
    return dp[n1][n2];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2);
    return 0;
}