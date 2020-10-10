#include <bits/stdc++.h>

using namespace std;

bool ismatch(string s, string p)
{
    int ns = s.size(), np = p.size();
    vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1));

    for (int i = 0; i <= ns; i++)
    {
        for (int j = 0; j <= np; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                    dp[0][0] = 1;
                else if (p[j - 1] == '*')
                    dp[0][j] = dp[0][j - 2];
                else
                    dp[0][j] = 0;
            }
            else if (j == 0)
                dp[i][0] = 0;
            else
            {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2];
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                else
                    dp[i][j] = false;
            }
        }
    }
    return dp[ns][np];
}

int main()
{
    string s, p;
    cin >> s >> p;
    cout << ismatch(s, p);
}