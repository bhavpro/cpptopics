#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
vector<int> g[N];
vector<int> ap;
vector<pair<int, int>> bridge;
vector<int> low;
vector<int> disc;
int t = 0;

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

int main()
{
    insert(1, 2);
    insert(2, 3);
    insert(1, 3);
    insert(3, 4);
    insert(4, 5);
    insert(4, 8);
    insert(6, 5);
    insert(6, 7);
    insert(4, 7);

    t = 0;
    dldfs(1, 0);
    for (int x : ap)
        cout << x << " ";
    return 0;
}