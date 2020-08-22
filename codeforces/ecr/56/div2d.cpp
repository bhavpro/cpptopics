#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int mod = 1e9;

void addedge(vector<int> g[], int a, int b)
{
    g[a].push_back(b);
    g[b].push_back(a);
}

bool checkbipartite(vector<int> g[], int cur, int par, unordered_map<int, bool> &vis, unordered_map<int, bool> &colour, bool col, int &noon)
{
    // base

    // rec
    noon++;
    colour[cur] = col;
    for (int ch : g[cur])
    {
        if (!vis[ch])
        {
            if (!checkbipartite(g, ch, cur, vis, colour, !col, noon))
            {
                return false;
            }
        }
        else if (ch != par)
        {
            if (col != colour[ch])
            {
                return false;
            }
        }
    }
    return true;
}

int powmod(int a, int p)
{
    // base
    if (p <= 1)
    {
        if (p == 0)
            return 1;
        else
            return a;
    }

    // rec
    long long x = powmod(a, p / 2);
    x = (x * x) % mod;
    if (p & 1)
    {
        x = (x * a) % mod;
    }
    return x;
}

int getcount(int n)
{
    long long nearans = powmod(2, n / 2);
    if (n & 1)
    {
        nearans *= 3;
    }
    else
    {
        nearans *= 2;
    }
    nearans %= mod;
    return nearans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> g[N];
        int v, e;
        cin >> v >> e;
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            addedge(g, a, b);
        }
        unordered_map<int, bool> vis, coloured;
        int prod = 1;
        for (int i = 1; i <= e; i++)
        {
            if (!vis[i])
            {
                {
                    int noon = 0;
                    if (!checkbipartite(g, 1, 0, vis, coloured, 0, noon))
                    {
                        cout << 0 << "\n";
                        break;
                    }
                    prod = (prod * getcount(noon)) % mod;
                }
            }
        }
        // if bipartite
        cout << prod << "\n";
    }
    return 0;
}