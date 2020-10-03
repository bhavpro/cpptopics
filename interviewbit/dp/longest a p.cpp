#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int> &A)
{
    int n = A.size();
    int mac = 0;
    vector<unordered_map<int, int>> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
        mac = max(1, mac);
        for (int j = i - 1; j >= 0; j--)
        {
            int diff = A[i] - A[j];
            if (dp[j][diff] > 0)
                dp[i][diff] = max(dp[j][diff] + 1, dp[i][diff]);
            else
                dp[i][diff] = 2;
            mac = max(mac, dp[i][diff]);
        }
    }
    return mac;
}
