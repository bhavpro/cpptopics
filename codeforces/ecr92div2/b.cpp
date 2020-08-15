#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> dp;

int rec(int *a, int n, int k, int z, int i = 0, bool left = true)
{
    // base
    if (k == 0)
    {
        dp[i][k][z] = a[i];
        return a[i];
    }

    // rec
    int ans1 = 0;
    if (left == true && z > 0 && i > 0)
    {
        ans1 = dp[i - 1][k - 1][z - 1] != 0 ? dp[i - 1][k - 1][z - 1] : rec(a, n, k - 1, z - 1, i - 1, false);
    }

    int ans2 = 0;
    if (i < n - 1)
    {
        ans2 = dp[i + 1][k - 1][z] != 0 ? dp[i + 1][k - 1][z] : rec(a, n, k - 1, z, i + 1, true);
    }
    dp[i][k][z] = a[i] + max(ans1, ans2);
    return dp[i][k][z];
}

int solve(int *a, int n, int k, int z)
{
    return rec(a, n, k, z);
}

int main()
{
   // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, z;
        cin >> n >> k >> z;
        int *a = new int[n];
        dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(k + 1, vector<int>(z + 1, 0)));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << solve(a, n, k, z) << "\n";
        delete[] a;
    }
    return 0;
}