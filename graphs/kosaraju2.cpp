#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
vector<int> g[N], gr[N];
#define pb push_back
vector<int> order;
bitset<100005> vis;
vector<int> comp[N];

void dfs(int cur)
{
    // base

    // rec
    vis[cur] = 1;
    for (int ch : g[cur])
    {
        if (!vis[ch])
        {
            dfs(ch);
        }
    }
    order.pb(cur);
}

void dfsrev(int cur, int count)
{
    // base

    // rec
    vis[cur] = 1;
    comp[count].pb(cur);
    for (int ch : gr[cur])
    {
        if (!vis[ch])
        {
            dfsrev(ch, count);
        }
    }
}

void isstongly(int n, int e)
{
    int count = 0;
    vis.reset();
    order.pb(-1);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    vis.reset();
    for (int i = n; i >= 1; i--)
    {
        if (!vis[order[i]])
        {
            dfsrev(order[i], count);
            count++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        cout << "\n"
             << i << " -> ";
        for (int ch : comp[i])
        {
            cout << ch << " , ";
        }
    }
}

int main()
{
     freopen("input.txt", "r", stdin);
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        gr[y].pb(x);
    }
    isstongly(n, e);
    return 0;
}