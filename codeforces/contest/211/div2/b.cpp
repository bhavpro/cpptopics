#include <bits/stdc++.h>

using namespace std;

int rec(int *h, int n, int k)
{
    int lenm = n + 1 - k;
    int *dp = new int[lenm];
    int wsum = 0;
    for (int i = 0; i < k; i++)
    {
        wsum += h[i];
    }
    int mini = wsum;
    int ind = 0;
    for (int i = 1; i < lenm; i++)
    {
        wsum -= h[i - 1];
        wsum += h[i + k - 1];
        dp[i] = wsum;
        if (mini > wsum)
        {
            ind = i;
            mini = wsum;
        }
    }
    return ind + 1;
}

int main()
{
   // freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int *h = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    int ans = rec(h, n, k);
    cout << ans;
    return 0;
}