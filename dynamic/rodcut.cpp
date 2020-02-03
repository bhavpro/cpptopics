#include <iostream>
#include <algorithm>

using namespace std;

int memo[10];

int profit(int arr[], int n)
{
    // base
    if (n <= 1)
    {
        return arr[n];
    }

    // rec
    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        int p = memo[n - i] == 0 ? profit(arr, n - i) : memo[n - i];
        m = max(m, max(arr[n], p + arr[i]));
    }
    memo[n] = m;
    return m;
}

int profitdp(int arr[], int n)
{
    // base
    int dp[10] = {0};
    dp[0] = 0;
    dp[1] = arr[1];

    // rec
    for (int i = 2; i <= n; i++)
    {
        // we are calc for length i
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], dp[i - j] + arr[j]);
        }
    }
    return dp[n];
}

int main()
{
    int n;
    n = 4;
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 2;
    arr[4] = 5;
    cout << profitdp(arr, n);
    delete[] arr;
    return 0;
}