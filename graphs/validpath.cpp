#include <bits/stdc++.h>

using namespace std;

#define sqr(x) (x) * (x)

bool toci(int row, int col, int n, int r, vector<int> &x, vector<int> &y)
{
    for (int i = 0; i < n; i++)
    {
        if (sqrt(sqr(row - x[i]) + sqr(col - y[i])) <= r)
            return true;
    }
    return false;
}

bool isvalid(int r, int c, int x, int y)
{
    if (r >= 0 && r <= x && c >= 0 && c <= y)
        return true;
    return false;
}

string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{
    int x = A, y = B, N = C, R = D;
    unordered_map<int, unordered_map<int, bool>> vis;

    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int r = cur.first;
        int c = cur.second;
        if (r == x && c == y)
            return "YES";
        for (int i = -1; i <= 1; i++)
            for (int j = -1; j <= 1; j++)
                if ((i != 0 || j != 0) && !vis[r + i][c + j] && isvalid(r + i, c + j, x, y) && !toci(r + i, c + j, N, R, E, F))
                {
                    vis[r + i][c + j] = true;
                    q.push({r + i, c + j});
                }
    }

    return "NO";
}
