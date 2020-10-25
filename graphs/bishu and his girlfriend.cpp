#include <bits/stdc++.h>

using namespace std;

vector<int> g[1001];

void insert(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

int choosegirl(unordered_map<int, bool> &country, int n, int c)
{
    int optdist = INT_MAX;
    unordered_map<int, bool> vis;
    queue<pair<int, int>> q;
    q.push({1, 0});
    vis[1] = 1;
    int ansset = INT_MAX;
    while (!q.empty())
    {
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        for (int x : g[cur])
        {
            if (!vis[x])
            {
                if (dist > optdist)
                    return ansset;
                vis[x] = 1;
                q.push({x, dist + 1});
                if (country[x] && optdist == INT_MAX)
                    optdist = dist + 1;
                if (country[x])
                    ansset = min(ansset, x);
            }
        }
    }
    return ansset;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        insert(a, b);
    }

    int c;
    cin >> c;
    unordered_map<int, bool> country;
    for (int i = 0; i < c; i++)
    {
        int a;
        cin >> a;
        country[a] = 1;
    }

    cout << choosegirl(country, n, c);

    return 0;
}