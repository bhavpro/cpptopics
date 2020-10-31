#include <bits/stdc++.h>

using namespace std;

vector<int> g[10001];

bool istreedfs(unordered_map<int, bool> &vis, int n, int par)
{
    vis[n] = 1;
    for (int x : g[n])
    {
        if (!vis[x])
        {
            if (!istreedfs(vis, x, n))
                return false;
        }
        else if (par != x)
            return false;
    }
    return true;
}

bool istree(int n)
{
    unordered_map<int, bool> vis;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (!istreedfs(vis, i, -1))
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    cout << (istree(n) == 1 ? "YES" : "NO");
}