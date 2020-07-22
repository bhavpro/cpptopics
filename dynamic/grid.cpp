#include <bits/stdc++.h>

using namespace std;

int ratdp(int r, int c)
{
    vector<vector<int>> dp(r, vector<int>(c, 1));
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[r - 1][c - 1];
}

int ratp(int r, int c)
{
    int num = r - 1 + c - 1;
    vector<int> dpfact(num + 1, 1);
    for (int i = 2; i <= num; i++)
    {
        dpfact[i] = dpfact[i - 1] * i;
    }
    return (dpfact[num] / (dpfact[r - 1] * dpfact[c - 1]));
}

int elephantdp(int r, int c)
{
    vector<vector<int>> dp(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = 0;
            //sum all above rows
            [i, j, &dp]() {
                for (int t = 0; t < i; t++)
                {
                    dp[i][j] += dp[t][j];
                }
            }();

            // sum all left columns
            [i, j, &dp]() {
                for (int t = 0; t < j; t++)
                {
                    dp[i][j] += dp[i][t];
                }
            }();
        }
    }
    return dp[r - 1][c - 1];
}

int main()
{
    int r, c;
    cin >> r >> c;
    cout << elephantdp(r, c);
    return 0;
}