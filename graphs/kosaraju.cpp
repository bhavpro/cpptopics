#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
vector<int> g[N], gr[N];
bitset<N> vis;
vector<int> order;
vector<int> comp;

void dfs(int cur)
{
    vis[cur] = 1;
    for (int child : g[cur])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
    order.push_back(cur);
}

void dfsrev(int cur, int col)
{
    comp[cur] = col;
    vis[cur] = 1;
    for (int child : gr[cur])
    {
        if (!vis[child])
        {
            dfsrev(child, col);
        }
    }
}

void insert(int a, int b)
{
    g[a].push_back(b);
    gr[b].push_back(a);
}

int main()
{
    vis.reset();
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        insert(a, b);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    vis.reset();
    int col = 0;

    for (int i = n; i >= 1; i--)
    {
        int ele = order[i];
        if (!vis[ele])
        {
            col++;
            dfsrev(ele, col);
        }
    }
    cout << "here" << flush;

    for (int i = 1; i < n; i++)
    {
        cout << i << " --> " << comp[i];
    }

    return 0;
}