#include <bits/stdc++.h>

using namespace std;

int minsteps(int n)
{
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            dp[0] = 0;
        else
        {
            dp[i] = INT_MAX;
            int temp = i;
            while (temp > 0)
            {
                if (temp % 10 != 0)
                    dp[i] = min(dp[i], dp[i - temp % 10] + 1);
                temp /= 10;
            }
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << minsteps(n);
}