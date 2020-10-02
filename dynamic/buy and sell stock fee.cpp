#include <bits/stdc++.h>

using namespace std;

int maxp(vector<int> price, int fee)
{
    int n = price.size();
    vector<pair<int, int>> dp(n);
    dp[0] = {-price[0], 0};
    for (int i = 1; i < n; i++)
    {
        pair<int, int> prev = dp[i - 1];
        dp[i] = {max(prev.first, prev.second - price[i]), max(prev.second, price[i] - fee + prev.first)};
    }
    return dp[n - 1].second;
}

int main()
{
    vector<int> a({10, 15, 17, 20, 16, 18, 22, 20, 22, 20, 23, 25});
    int fee = 3;
    cout << maxp(a, fee);
    return 0;
}