#include <bits/stdc++.h>

using namespace std;

struct triplet
{
    int f, s, t;
};

int maxp(vector<int> price)
{
    int n = price.size();
    vector<triplet> dp(n);
    dp[0] = {-price[0], 0, 0};
    for (int i = 1; i < n; i++)
    {
        triplet prev = dp[i - 1];
        dp[i] = {max(prev.f, prev.t - price[i]), max(prev.s, price[i] + prev.f), max(prev.t, prev.s)};
    }
    return dp[n - 1].s;
}

int main()
{
    vector<int> a({10, 15, 17, 20, 16, 18, 22, 20, 22, 20, 23, 25});
    cout << maxp(a);
    return 0;
}