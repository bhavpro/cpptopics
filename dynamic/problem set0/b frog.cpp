#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int *h = new int[n];
    int *dp = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[0] = 0;
            continue;
        }
        dp[i] = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j < 0)
            {
                break;
            }
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    cout << dp[n - 1];
    delete[] h;
    delete[] dp;
    return 0;
}