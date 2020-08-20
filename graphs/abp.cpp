#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
vector<int> g[N];
vector<int> ap;
vector<pair<int, int>> bridge;
vector<int> low;
vector<int> disc;
bitset<N> col;
bitset<N> vis;
int t = 0;
vector<int> dist(N);

void insert(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

void dldfs(int cur, int par)
{
    int noc = 0;
    // base

    // rec
    t++;
    disc[cur] = t;
    low[cur] = t;
    for (int ch : g[cur])
    {
        if (!disc[ch]) // not visited
        {
            noc++;
            dldfs(ch, cur);
            low[cur] = min(low[cur], low[ch]);
            if (par != 0 && low[ch] >= disc[cur])
            {
                ap.push_back(cur);
            }
            if (low[ch] > disc[cur])
            {
                bridge.push_back({cur, ch});
            }
        }
        else if (ch != par)
        {
            low[cur] = min(low[cur], disc[ch]);
        }
        else
        {
        }
    }

    if (noc >= 2 && par == 0)
    {
        ap.push_back(cur);
    }
}

bool bipardfs(int cur, int par, bool col)
{
    // base

    // rec
    vis[cur] = 1;
    ::col[cur] = col;
    for (auto ch : g[cur])
    {
        if (!vis[ch])
        {
            if (!bipardfs(ch, cur, !col))
            {
                return false;
            }
        }
        else if (par != ch)
        {
            if (::col[ch] == ::col[cur])
            {
                return false;
            }
        }
    }
    return true;
}
int shortest()
{
    int mind = INT_MAX;
    for (int i = 1; i <= 6; i++)
    {
        vis.reset();
        for (int j = 0; j < 10; j++)
        {
            dist[j] = 0;
        }
        queue<pair<int, int>> q;
        q.push({i, 0});
        dist[i] = 0;
        while (!q.empty())
        {
            auto f = q.front();
            q.pop();
            for (int ch : g[f.first])
            {
                if (!vis[ch])
                {
                    q.push({ch, f.first});
                    dist[ch] = dist[f.first] + 1;
                    vis[ch] = 1;
                }
                else if (ch != f.second)
                {
                    mind = min(mind, dist[ch] + dist[f.first] + 1);
                }
            }
        }
    }
    return mind;
}



int main()
{
    insert(1, 2);
    insert(2, 3);
    insert(2, 4);
    insert(3, 5);
    insert(4, 5);
    insert(4, 6);
    insert(6, 5);
    //insert(6, 7);
    //insert(4, 7);
    //   t = 0;
    // dldfs(1, 0);
    // for (int x : ap)
    //   cout << x << " ";
    //cout << bipardfs(1, 0, 0);
    cout << shortest();
    return 0;
}