#include <iostream>
#include <utility>

using namespace std;

int lis(int a[], int n, int j = 0)
{
    static int memo[20];
    // base
    if (j == n)
    {
        int mexi = 1;
        for (int i = 0; i < n; i++)
        {
            mexi = max(mexi, memo[i]);
        }
        return mexi;
    }

    if (j == 0)
    {
        for (int i = 0; i < n; i++)
        {
            memo[i] = 1;
        }
        return lis(a, n, 1);
    }

    // rec
    for (int i = 0; i < j; i++)
    {
        if (a[i] < a[j])
        {
            memo[j] = max(memo[i] + 1, memo[j]);
        }
    }

    return lis(a, n, j + 1);
}

int lisdp(int a[], int n)
{
    int dp[20];

    for (int j = 0; j < n; j++)
    {
        // base
        dp[j] = 1;

        // rec
        for (int i = 0; i < j; i++)
        {
            if (a[i] < a[j])
            {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    int mexi = 0;
    for (int i = 0; i < n; i++)
    {
        mexi = max(mexi, dp[i]);
    }
    return mexi;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << lis(arr, n);
    cout << "\n"
         << lisdp(arr, n);
    delete[] arr;
    return 0;
}