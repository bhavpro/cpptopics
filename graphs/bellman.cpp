#include <bits/stdc++.h>

using namespace std;

#define inf 1e9

struct Edge
{
    int src, dest, wt;
};

class Graph
{
public:
    int v, e;
    Edge *ea;

    Graph(int v, int e) : v(v), e(e)
    {
        ea = new Edge[e];
    }

    void addedge(int u, int v, int w, int count)
    {
        ea[count].src = u;
        ea[count].dest = v;
        ea[count].wt = w;
    }

    void bellman(int src)
    {
        int dist[v];
        for (int i = 0; i < v; i++)
        {
            dist[i] = inf;
        }
        dist[src] = 0;

        for (int i = 1; i <= v - 1; i++)
        {
            for (int j = 0; j < e; j++)
            {
                Edge cure = ea[j];
                int tempdist = dist[cure.src] + cure.wt;
                dist[cure.dest] = min(dist[cure.dest], tempdist);
            }
        }

        bool negc = 0;
        for (int i = 0; i < e; i++)
        {
            Edge cure = ea[i];
            int tempdist = dist[cure.src] + cure.wt;
            if (tempdist <  dist[cure.dest])
                negc = 1;
        }
        if (!negc)
            for (int i = 0; i < v; i++)
                cout << i << " --> " << dist[i] << "\n";
        else
            cout << "Negative Cycle Present";
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    int v, e;
    cin >> v >> e;
    Graph g(v, e);
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        g.addedge(s, d, w, i);
    }
    g.bellman(0);
    return 0;
}