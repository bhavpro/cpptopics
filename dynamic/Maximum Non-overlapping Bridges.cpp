#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>

int mnob(vector<pi> bc)
{
    int n = bc.size();
    sort(bc.begin(), bc.end());
    vector<int> dp(n);
    dp[0] = 1;
    int maxi = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (bc[i].second > bc[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int main()
{
    int n;
    cin >> n;
    vector<pi> arr(n);
    for (pi &a : arr)
    {
        cin >> a.first >> a.second;
    }
    cout << mnob(arr);
    return 0;
}