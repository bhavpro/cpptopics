#include <bits/stdc++.h>

using namespace std;

int maxSubsetSum(vector<int> arr)
{
    int n = arr.size();
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = (arr[0] <= 0 ? 0 : arr[0]);
    for (int i = 2; i <= n; i++)
    {
        int op1 = arr[i - 1] + dp[i - 2];
        int op2 = dp[i - 1];
        dp[i] = max(op1, op2);
    }

    int ans = dp[n];
    delete[] dp;
    return ans;
}

string abbreviation(string a, string b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));
    for (int i = 0; i <= a.size(); i++)
    {
        for (int j = 0; j <= b.size(); j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            if (i == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (j == 0)
            {
                if (islower(a[i - 1]) && dp[i - 1][j])
                {
                    dp[i][j] = 1;
                }
            }
            if (toupper(a[i - 1]) == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j];
                continue;
            }
            if (islower(a[i - 1]))
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = 0;
        }
    }
    return (dp[a.size()][b.size()] == 1 ? "YES" : "NO");
}

int main()
{
    return 0;
}