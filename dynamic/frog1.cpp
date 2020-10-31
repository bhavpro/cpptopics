#include <bits/stdc++.h>

using namespace std;

int mincost(vector<int> h, int n)
{
    if (n <= 1)
        return 0;
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &x : h)
        cin >> x;

    cout << mincost(h, n);
    return 0;
}