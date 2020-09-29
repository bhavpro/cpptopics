#include <bits/stdc++.h>

using namespace std;

int ways4(int n)
{
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        if (i < 4)
            dp[i] = 1;
        else
            dp[i] = dp[i - 1] + dp[i - 4];
    }
    return dp[n];
}

int waysm(int n, int m)
{
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        if (i < m)
            dp[i] = 1;
        else
            dp[i] = dp[i - 1] + dp[i - m];
    }
    return dp[n];
}

int main()
{
    cout << waysm(5, 4);
}