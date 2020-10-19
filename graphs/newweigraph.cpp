#include <bits/stdc++.h>

using namespace std;

class graph
{
public:
    vector<list<pair<int, int>>> adj;

    graph(int v)
    {
        adj.resize(v);
    }

    void addedge(int s, int d, int w, bool bidir = true)
    {
        adj[s].push_back({d, w});
        if (bidir)
            adj[d].push_back({s, w});
    }

    int minpathuw(int s, int d);
    bool ispath(int s, int d);
    bool ispathdfshelper(int s, int d, unordered_map<int, bool> &vis);
    bool ispathcurstack(int s, int d);
    void allpaths(int s, int d);
    void allpathshelper(int s, int d, unordered_map<int, bool> &vis, string str);
};

int graph::minpathuw(int s, int d)
{
    int dist = -1;
    unordered_map<int, int> parent;
    unordered_map<int, bool> vis;
    queue<pair<int, int>> q;
    q.push({s, 0});
    vis[s] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        if (par.first == d)
        {
            dist = par.second;
            break;
        }
        for (pair<int, int> p : adj[par.first])
        {
            int ch = p.first;
            if (!vis[ch])
            {
                vis[ch] = 1;
                q.push({ch, par.second + 1});
                parent[ch] = par.first;
            }
        }
    }

    int dist2 = 0;
    int e = d;
    cout << "\n";
    while (e != s)
    {
        dist2++;
        cout << e << " --> ";
        e = parent[e];
    }
    cout << e << "\n";

    if (dist2 == dist)
        return dist;
    else
        return -1;
}

bool graph::ispathdfshelper(int s, int d, unordered_map<int, bool> &vis)
{
    // base
    if (s == d)
        return true;
    // rec
    for (pair<int, int> ch : adj[s])
    {
        if (!vis[ch.first])
        {
            vis[ch.first] = true;
            if (ispathdfshelper(ch.first, d, vis))
                return true;
        }
    }
    return false;
}

bool graph::ispath(int s, int d)
{
    unordered_map<int, bool> vis;
    vis[s] = true;
    return ispathdfshelper(s, d, vis);
}

bool graph::ispathcurstack(int s, int d)
{
    unordered_map<int, bool> vis;
    vis[s] = true;

    stack<int> memstack;
    memstack.push(s);
    while (!memstack.empty())
    {
        int curs = memstack.top();
        memstack.pop();
        if (curs == d)
            return true;
        for (pair<int, int> p : adj[curs])
        {
            if (!vis[p.first])
            {
                vis[p.first] = true;
                memstack.push(p.first);
            }
        }
    }
    return false;
}

void graph::allpathshelper(int s, int d, unordered_map<int, bool> &vis, string str)
{
    // base
    if (s == d)
    {
        stringstream ss;
        ss << s;
        str += "->" + ss.str();
        cout << str << "\n";
        return;
    }
    // rec
    stringstream ss;
    ss << s;
    str += "->" + ss.str();
    for (pair<int, int> p : adj[s])
    {
        int ch = p.first;
        if (!vis[ch])
        {
            vis[ch] = true;
            allpathshelper(ch, d, vis, str);
            vis[ch] = false;
        }
    }
}

void graph::allpaths(int s, int d)
{
    unordered_map<int, bool> vis;
    vis[s] = true;
    string str = "";
    allpathshelper(s, d, vis, str);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int e, v;
    cin >> v >> e;
    graph g(v + 1);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g.addedge(a, b, c);
    }
    return 0;
}