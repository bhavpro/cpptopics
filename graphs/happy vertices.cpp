#include <bits/stdc++.h>

using namespace std;

struct graph
{
    int v;
    unordered_map<int, list<int>> adj;
    void addedge(int a, int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
};

int bfs(unordered_map<int, bool> &vis, int start, graph &g)
{
    int nohv = 0;
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int noch = 0;
        for (int ch : g.adj[cur])
        {
            if (!vis[ch])
            {
                noch++;
                vis[ch] = true;
                q.push(ch);
            }
        }
        if (noch > 1 && start != cur)
            nohv++;
    }
    return nohv;
}
int cnohv(graph &g)
{
    int nohv = 0;
    unordered_map<int, bool> vis;
    for (int i = 1; i <= g.v; i++)
    {
        if (!vis[i])
        {
            nohv += bfs(vis, i, g);
        }
    }
    return nohv;
}

int main()
{
    int v, e;
    cin >> v >> e;
    graph g;
    g.v = v;
    vector<int> children(v + 1, 0), parent(v + 1, 0);
    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        g.addedge(s, d);
    }

    cout << cnohv(g);

    return 0;
}