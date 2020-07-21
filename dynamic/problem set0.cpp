#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int fibonacco(int n)
{
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int x = dp[n];
    delete[] dp;
    return x;
}

int factorial(int n)
{
    int *fact = new int[n + 1];
    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i;
    }
    int ans = fact[n];
    delete[] fact;
    return ans;
}

int noto1(int n)
{
    // base
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 0;

    // rec
    for (int i = 2; i <= n; i++)
    {
        dp[i] = INT_MAX;
        dp[i] = i % 2 == 0 ? min(dp[i / 2] + 1, dp[i]) : dp[i];
        dp[i] = i % 3 == 0 ? min(dp[i / 3] + 1, dp[i]) : dp[i];
        dp[i] = min(dp[i - 1] + 1, dp[i]);
    }

    // end
    int x = dp[n];
    delete[] dp;
    return x;
}

int wine1d()
{
    

}

int main()
{
    int n = 6;
    // cout << fibonacco(n);
    // cout << factorial(n);
    cout << noto1(10);
    return 0;
}