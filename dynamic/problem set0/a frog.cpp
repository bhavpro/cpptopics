#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    int *dp = new int[n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[0] = 0;
            continue;
        }
        if (i == 1)
        {
            dp[1] = abs(h[0] - h[1]) + dp[0];
            continue;
        }
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n - 2];
    delete[] dp;
    return 0;
}