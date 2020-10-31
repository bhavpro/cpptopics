#include <bits/stdc++.h>

using namespace std;

int mincost(vector<int> h, int n, int k)
{
    if (n <= 1)
        return 0;
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = i - 1; j >= max(i - k, 0); j--)
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
    }
    return dp[n - 1];
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int &x : h)
        cin >> x;

    cout << mincost(h, n, k);
    return 0;
}