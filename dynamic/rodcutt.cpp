#include <bits/stdc++.h>

using namespace std;

int rc(int *arr, int n, int len)
{
    // base
    if (len <= 0)
    {
        return 0;
    }

    // rec
    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        if (len - i >= 0)
        {
            max = ::max(rc(arr, n, len - i) + arr[i], max);
        }
    }
    return max;
}

int dprc(int *a, int n, int len)
{
    int *dp = new int[len + 1];

    for (int i = 0; i <= len; i++)
    {
        if (i == 0)
        {
            dp[0] = 0;
            continue;
        }
        dp[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i - j < 0)
            {
                break;
            }
            dp[i] = ::max(dp[i], dp[i - j] + a[j]);
        }
    }

    int ans = dp[len];
    delete[] dp;
    return ans;
}

int main()
{
    int n = 4;
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 5;
    cout << dprc(arr, n, 10);
    delete[] arr;
    return 0;
}