#include <bits/stdc++.h>

using namespace std;

int solvedprd(vector<vector<int>> &garden, int sx, int sy, int ex, int ey)
{

    int r = ex - sx + 1;
    int c = ey - sy + 1;
    vector<vector<int>> dp(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = garden[i + sx][j + sy];
                continue;
            }
            dp[i][j] = max((i != 0 ? dp[i - 1][j] : 0), (j != 0 ? dp[i][j - 1] : 0));
            dp[i][j] += garden[i + sx][j + sy];
        }
    }
    return dp[r - 1][c - 1];
}

int solvedpru(vector<vector<int>> &garden, int sx, int sy, int ex, int ey)
{

    int r = sx - ex + 1;
    int c = ey - sy + 1;
    vector<vector<int>> dp(r, vector<int>(c, 0));
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == r - 1 && j == 0)
            {
                dp[i][j] = garden[sx - i][j + sy];
                continue;
            }
            dp[i][j] = max((i == r - 1 ? 0 : dp[i + 1][j]), (j == 0 ? 0 : dp[i][j - 1]));
            dp[i][j] += garden[sx - i][j + sy];
        }
    }
    return dp[0][c - 1];
}

int solve(vector<vector<int>> garden, int i, int j, int r, int c)
{
    // boy at top
    int sol1 = solvedprd(garden, 1, 1, i - 1, j);
    int sol2 = solvedprd(garden, i + 1, j, r, c);
    int sol3 = solvedpru(garden, r, 1, i, j - 1);
    int sol4 = solvedpru(garden, i, j + 1, 1, c);
    int ans = sol1 + sol2 + sol3 + sol4;

    // boy at left
    sol1 = solvedprd(garden, 1, 1, i, j - 1);
    sol2 = solvedprd(garden, i, j + 1, r, c);
    sol3 = solvedpru(garden, r, 1, i + 1, j);
    sol3 = solvedpru(garden, i - 1, j, 1, c);
    return max(ans, sol1 + sol2 + sol3 + sol4);
}

int main()
{
    int r, c;
    r = c = 3;
    vector<vector<int>> garden(r + 1, vector<int>(c + 1, -1));
    for (int i = 1; i <= 3; i++)
    {
        garden[1][i] = garden[3][i] = 100;
    }
    garden[2][1] = garden[2][3] = 100;
    garden[2][2] = 1;
    int ans = -1;
    for (int i = 2; i <= r - 1; i++)
    {
        for (int j = 2; j <= c - 1; j++)
        {
            ans = max(ans, solve(garden, i, j, r, c));
        }
    }
    cout << ans;
    return 0;
}