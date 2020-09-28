#include <bits/stdc++.h>

using namespace std;

int maxsum(vector<int> arr)
{
    int n = arr.size();
    vector<pair<int, int>> dp(n);
    dp[0].first = arr[0];
    dp[0].second = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i].first = dp[i - 1].second + arr[i];
        dp[i].second = max(dp[i - 1].first, dp[i - 1].second);
    }
    return max(dp[n - 1].first, dp[n - 1].second);
}

int main()
{
    vector<int> arr({5, 10, 10, 100, 5, 6});
    cout << maxsum(arr);
}