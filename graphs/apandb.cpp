#include <bits/stdc++.h>

using namespace std;

vector<int> g[1001];
int lowest[1001], disc[1000]={0};
int t;
set<int> ap;
vector<pair<int, int>> bridges;

void dfs(int cur, int par)
{
    // base

    // rec
    int noc = 0;
    t++;
    disc[cur] = t;
    lowest[cur] = t;
    for (int ch : g[cur])
    {
        if (disc[ch] == 0)
        {
            noc++;
            dfs(ch, cur);
            lowest[cur] = min(lowest[cur], lowest[ch]);
            if (par != -1 && lowest[ch] >= disc[cur])
            {
                ap.insert(cur);
            }
            if (lowest[ch] > disc[cur])
            {
                bridges.push_back({cur, ch});
            }
        }
        else if (ch != par)
        {
            lowest[cur] = min(disc[ch], lowest[cur]);
        }
    }
    if (noc > 1 && par == -1)
    {
        ap.insert(cur);
    }
}

void apb(int v, int e)
{
    for (int i = 1; i <= v; i++)
    {
        if (disc[i] == 0)
        {
            t = 0;
            dfs(i, -1);
        }
    }
    cout << "APs are : ";
    for (int ele : ap)
    {
        cout << ele << " ";
    }

    cout << "\n\n Bridges are : ";
    for (pair<int, int> p : bridges)
    {
        cout << p.first << "--" << p.second << "  ";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int s, d;
        cin >> s >> d;
        g[s].push_back(d);
        g[d].push_back(s);
    }
    apb(v, e);
    return 0;
}