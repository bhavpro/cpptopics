#include <bits/stdc++.h>

using namespace std;

int count(string a)
{
    int n = a.size();
    vector<vector<int>> dp(3, vector<int>(n + 1));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j == 0)
                dp[i][j] = 0;
            else if (i == 0 && a[j - 1] == 'a')
            {
                dp[i][j] = (dp[i][j - 1] << 1) + 1;
            }
            else if (i == 1 && a[j - 1] == 'b')
            {
                dp[i][j] = (dp[i][j - 1] << 1) + dp[i - 1][j - 1];
            }
            else if (i == 2 && a[j - 1] == 'c')
            {
                dp[i][j] = (dp[i][j - 1] << 1) + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[2][n];
}

int main()
{
    string s = "abcabc";
    cout << count(s);
}