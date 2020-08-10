#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int v;
    list<pair<int, int>> *adj;

    Graph(int v) : v(v)
    {
        adj = new list<pair<int, int>>[v];
    }

    ~Graph()
    {
        delete[] adj;
    }

    void addedge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int findmin(int *wei, int n, bitset<40000> visited)
    {
        int mini = n;
        int w = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (wei[i] < w && !visited[i])
            {
                w = wei[i];
                mini = i;
            }
        }
        return mini;
    }

    void prims()
    {
        int *par = new int[v];
        int *wei = new int[v];
        bitset<40000> visited;
        visited.reset();
        for (int i = 0; i < v; i++)
        {
            wei[i] = INT_MAX;
        }
        par[0] = -1;
        wei[0] = 0;

        for (int j = 0; j < v; j++)
        {
            int i = findmin(wei, v, visited);
            if (visited[i])
            {
                continue;
            }
            visited[i] = 1;
            for (pair<int, int> p : adj[i])
            {
                int w = p.second;
                int cpar = p.first;
                if (wei[cpar] > w && !visited[cpar])
                {
                    wei[cpar] = w;
                    par[cpar] = i;
                }
            }
        }
        visited.reset();
        for (int i = 1; i < v; i++)
        {

            cout << par[i] << " --> " << i << " : " << wei[i] << "\n";
        }

        delete[] par;
        delete[] wei;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g.addedge(a, b, c);
    }
    g.prims();
    return 0;
}