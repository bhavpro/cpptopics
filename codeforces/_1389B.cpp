#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> arr, int k, int z)
{
    int n = arr.size();
    vector<vector<int>> dp(k + 1, vector<int>(z + 1));
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= z; j++)
        {
            dp[i][j] = 0;
            if (i == 0)
            {
                dp[0][j] = arr[0];
                continue;
            }
            if (j == 0)
            {
                dp[i][0] = dp[i - 1][0] + arr[i];
                continue;
            }
            if (j > 0 && i > 1)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i - 2]);
            }
            dp[i][j] = max(dp[i][j], arr[i] + dp[i - 1][j]);
        }
    }
    return dp[k][z];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    int t, n, k, z;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> z;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(arr, k, z) << "\n";
    }
}