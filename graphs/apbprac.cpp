#include <bits/stdc++.h>

using namespace std;

vector<int> g[40];
int disc[40], low[40], t;
unordered_set<int> ap;
vector<pair<int, int>> bridge;

void insert(int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

void findapb(int cur, int par)
{
    // base

    // rec
    int noc = 0;
    t++;
    disc[cur] = t;
    low[cur] = t;
    for (int ch : g[cur])
    {
        if (!disc[ch])
        {
            noc++;
            findapb(ch, cur);
            low[cur] = min(low[cur], low[ch]);
            if (par != 0 && low[ch] >= disc[cur])
                ap.insert(cur);
            if (low[ch] > disc[cur])
                bridge.push_back({cur, ch});
        }
        else if (ch != par)
        {
            low[cur] = min(low[cur], disc[ch]);
        }
    }
    if (!par && noc >= 2)
        ap.insert(cur);
}

int main()
{
    insert(1, 2);
    insert(2, 3);
    insert(4, 3);
    insert(7, 4);
    insert(7, 10);
    insert(4, 10);
    insert(3, 5);
    insert(5, 8);
    insert(3, 8);
    insert(3, 6);
    insert(6, 9);
    insert(9, 2);
    t = 0;
    findapb(1, 0);

    for (int x : ap)
        cout << x << " ";

    cout << "\n\n";

    for (pair<int, int> x : bridge)
        cout << x.first << " -- " << x.second << "\n";
    return 0;
}