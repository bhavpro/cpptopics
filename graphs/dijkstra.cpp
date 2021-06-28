#include <iostream>
#include <climits>

using namespace std;

int getmindistele(int *dist, bool *vis, int v)
{
    int cur = 0;
    int curd = INT_MAX;
    for (int i = 0; i < v; i++)
        if (!vis[i] && dist[i] <= curd)
        {
            cur = i;
            curd = dist[i];
        }
    return cur;
}

void dijkstras(int **edge, int v, int e, int src)
{
    int *dist = new int[v];
    bool *vis = new bool[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
        vis[i] = false;
    }
    dist[src] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        int ele = getmindistele(dist, vis, v);
        for (int j = 0; j < v; j++)
            if (ele != j && !vis[j] && edge[ele][j] != 0)
                dist[j] = min(dist[j], dist[ele] + edge[ele][j]);
        vis[ele] = true;
    }

    for (int i = 0; i < v; i++)
    {
        cout << "\n"
             << src << " -- " << i << " : " << dist[i];
    }

    delete[] dist;
    delete[] vis;
}

int main()
{
    int v, e;
    cin >> v >> e;
    int **edge = new int *[v];
    for (int i = 0; i < v; i++)
    {
        edge[i] = new int[v];
        for (int j = 0; j < v; j++)
            edge[i][j] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        cout << "\nEdge " << i << " : ";
        int s, d, w;
        cin >> s >> d >> w;
        edge[s][d] = w;
        edge[d][s] = w;
    }

    dijkstras(edge, v, e, 0);
    cout << "\n\n";
    dijkstras(edge, v, e, 2);

    for (int i = 0; i < v; i++)
        delete[] edge[i];
    delete[] edge;

    return 0;
}