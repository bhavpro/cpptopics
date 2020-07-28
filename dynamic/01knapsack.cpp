#include <bits/stdc++.h>

using namespace std;

int wts[] = {2, 2, 3, 4};
int price[] = {5, 20, 20, 10};
int coun = 0;
vector<vector<int>> memo(50, vector<int>(50, -1));

int rec(int bw, int n, int i = 0)
{
    coun++;
    // base
    if (i == n)
    {
        return 0;
    }

    // rec
    int sel = 0;
    if (bw - wts[i] >= 0)
        sel = price[i] + (memo[bw][i] == -1 ? rec(bw - wts[i], n, i + 1) : memo[bw - wts[i]][i + 1]);
    int unsel = (memo[bw][i + 1] == -1 ? rec(bw, n, i + 1) : memo[bw][i + 1]);
    memo[bw][i] = max(sel, unsel);
    return memo[bw][i];
}

int dp(int bw, int n)
{
    int dp[100][100];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= bw; j++)
        {
            coun++;
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            int sel = 0;
            if (j - wts[i - 1] >= 0)
            {
                sel = dp[i - 1][j - wts[i - 1]] + price[i - 1];
            }
            int unsel = dp[i - 1][j];
            dp[i][j] = max(sel, unsel);
        }
    }
    return dp[n][bw];
}

int main()
{
    int n = 4;
    int w = 5;
    cout << dp(w, n);
    cout << " " << coun;
    return 0;
}