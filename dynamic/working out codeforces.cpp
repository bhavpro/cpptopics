#include <bits/stdc++.h>

using namespace std;

int rr, cc;

int solvedprd(const vector<vector<int>> &garden, int sx, int sy, int ex, int ey)
{
    int r = ex - sx;
    int c = ey - sy;
    vector<vector<int>> dp(rr + 1, vector<int>(cc + 1, 0));
    for (int i = sx; i <= ex; i++)
    {
        for (int j = sy; j <= ey; j++)
        {
            if (i == sx && j == sy)
            {
                dp[i][j] = garden[i][j];
                continue;
            }
            
        }
    }
}

int solvedpru(const vector<vector<int>> &garden, int sx, int sy, int ex, int ey)
{
}

int solve(vector<vector<int>> garden, int i, int j)
{
    int r, c;
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
    rr = r;
    cc = c;
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
            ans = max(ans, solve(garden, i, j));
        }
    }
    cout << ans;
    return 0;
}