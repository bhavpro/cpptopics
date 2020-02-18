#include <iostream>

using namespace std;

int memo[20] = {0};

int countways(int n, int k)
{
    // base
    if (n <= 0)
    {
        return 1;
    }

    // rec
    int count = 0;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 0)
        {
            count += memo[n - i] == 0 ? countways(n - i, k) : memo[n - i];
        }
    }
    memo[n] = count;
    return count;
}

int countwaysdp(int n, int k)
{
    int dp[20];

    for (int i = 0; i <= n; i++)
    {
        // base
        if (i == 0)
        {
            dp[i] = 1;
            continue;
        }

        // rec
        int add = 0;
        for (int j = i - 1; j >= i - k && j >= 0; j--)
        {
            add += dp[j];
        }
        dp[i] = add;
    }
    return dp[n];
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    cout << countways(n, k);
    cout << "\n"
         << countwaysdp(n, k);
    return 0;
}