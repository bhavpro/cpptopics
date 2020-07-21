#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
vector<int> g[N];
int disc[N], low[N], t;
set<int> ap;
vector<pair<int, int>> bridges;

void insert(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

void dldfs(int cur, int par)
{
    int noofchild = 0;
    // base

    // rec
    t++;
    disc[cur] = t;
    low[cur] = t;
    for (int child : g[cur])
    {
        // if not visited
        if (disc[child] == 0)
        {
            dldfs(child, cur);
            low[cur] = min(low[cur], low[child]);
            if (low[child] >= disc[cur])
            {
                ap.insert(cur);
            }
            if (low[child] < disc[cur])
            {
                bridges.push_back(make_pair(cur, child));
            }
            noofchild++;
        }
        // back edge
        else if (child != par)
        {
            low[cur] = min(disc[child], low[cur]);
        }
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