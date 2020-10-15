#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &A)
{
    int n = A.size();
    vector<int> dp(n);
    dp[0] = A[0][0];
    int prev;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                prev = dp[0];
                dp[0] = prev + A[i][j];
            }
            else if (j == i)
            {
                dp[j] = prev + A[i][j];
            }
            else
            {
                int temp = dp[j];
                dp[j] = max(temp, prev) + A[i][j];
                prev = temp;
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}
