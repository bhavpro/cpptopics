#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>

int maxe(vector<pi> a)
{
    sort(a.begin(), a.end());
    int n = a.size();
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j].second < a[i].second && a[j].first < a[i].first)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    int n;
    cin >> n;
    vector<pi> arr(n);
    for (pi &x : arr)
        cin >> x.first >> x.second;
    cout << maxe(arr);
    return 0;
}