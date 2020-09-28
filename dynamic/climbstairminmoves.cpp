#include <bits/stdc++.h>

using namespace std;

int mins(vector<int> move, int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int ind = min(n, i + move[i]);
        for (int j = i + 1; j <= ind; j++)
        {
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }
    return dp[n];
}

int main()
{
    vector<int> dp({3, 2, 2, 1, 2});
    int n = 5;
    cout << mins(dp, n);
}