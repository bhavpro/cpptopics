#include <iostream>

using namespace std;

int memo[20] = {0};

int pairit(int n)
{
    // base
    if (n == 1 || n == 2)
        return n;

    if (n <= 0)
    {
        return 0;
    }

    // rec
    int a = memo[n - 1] == 0 ? pairit(n - 1) : memo[n - 1];
    int b = memo[n - 2] == 0 ? pairit(n - 2) : memo[n - 2];
    memo[n] = a + (n - 1) * b;
    return memo[n];
}

int pairitdp(int n)
{
    int dp[20];

    for (int i = 0; i <= n; i++)
    {
        if (i <= 2)
        {
            dp[i] = i;
            continue;
        }
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << pairitdp(n);
    return 0;
}