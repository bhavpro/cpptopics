#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("islandsinput.txt", "r", stdin);
    int r, c;
    cin >> r >> c;
    vector<vector<bool>> path(r, vector<bool>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int v;
            cin >> v;
            path[i][j] = v;
        }
    }

    vector<vector<bool>> vis(r, vector<bool>(c, false));
    int nocc = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (path[i][j] == 0 && !vis[i][j])
            {
                vis[i][j] = 1;
                nocc++;
                // bfs
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty())
                {
                    pair<int, int> f = q.front();
                    q.pop();
                    int ni = f.first;
                    int nj = f.second;
                    if (ni < r - 1 && !path[ni + 1][nj])
                    {
                        vis[ni + 1][nj] = 1;
                        q.push({ni + 1, nj});
                    }
                    if (nj < c - 1 && !path[ni][nj + 1])
                    {
                        q.push({ni, nj + 1});
                        vis[ni][nj + 1] = 1;
                    }
                }
            }
        }
    }
    cout << nocc;
    return 0;
}