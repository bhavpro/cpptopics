#include <iostream>

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

int main()
{
    int n = 6;
    // cout << fibonacco(n);
    cout << factorial(n);
    return 0;
}