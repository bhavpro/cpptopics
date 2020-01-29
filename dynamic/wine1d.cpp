#include <iostream>
#include <algorithm>

using namespace std;

int memo[10][10];

int profit(int arr[], int n, int cury = 1, int i = 0, int j = -1)
{
    // pre
    if (j == -1)
    {
        return profit(arr, n, cury, i, n - 1);
    }

    // base
    if (i == j)
    {
        memo[i][j] = arr[i] * cury;
        return memo[i][j];
    }

    // rec
    int a = memo[i + 1][j] == 0 ? profit(arr, n, cury + 1, i + 1, j) : memo[i + 1][j];
    int b = memo[i][j - 1] == 0 ? profit(arr, n, cury + 1, i, j - 1) : memo[i][j - 1];
    int c = max(a + cury * arr[i], b + cury * arr[j]);
    memo[i][j] = c;
    return c;
}

int profitdp(int arr[], int n)
{
    // base
    int dp[10][10];
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = arr[i] * n;
    }

    // rec
    for (int j = 1; j < n; j++)
    {
        int year = n - j;
        int k = j;
        for (int i = 0; i < n - j; i++)
        {
            int a = dp[i + 1][k] + arr[i] * year;
            int b = dp[i][k - 1] + arr[k] * year;
            dp[i][k] = max(a, b);
            k++;
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n;
    n = 5;
    int a[100];
    a[0] = 2;
    a[1] = 3;
    a[2] = 5;
    a[3] = 1;
    a[4] = 4;
    cout << profitdp(a, n);
    return 0;
}