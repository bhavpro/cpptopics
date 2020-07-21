#include <bits/stdc++.h>

using namespace std;

int ed(string init, string final)
{
    int n1 = init.size();
    int n2 = final.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

    // base
    for (int i = 0; i <= n1; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 0; i <= n2; i++)
    {
        dp[0][i] = i;
    }

    // rec
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            int ans = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
            ans = min(ans, dp[i - 1][j - 1] + (init[i - 1] == final[j - 1] ? 0 : 1));
            dp[i][j] = ans;
        }
    }
    return dp[n1][n2];
}

int main()
{
    string init, final;
    init = "saturday";
    final = "sunday";
    cout << ed(init, final);
    return 0;
}