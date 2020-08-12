#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            dp[0] = 1;
            continue;
        }
        if (i == 1)
        {
            dp[1] = 1;
            continue;
        }
        dp[i] = (i - 1) * dp[i - 2] + dp[i - 1];
    }
    cout << dp[n];
    delete[] dp;
    return 0;
}