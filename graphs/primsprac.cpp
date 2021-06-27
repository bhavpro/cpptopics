#include <iostream>
#include <climits>

using namespace std;

int minwele(int *wet, bool *vis, int v)
{
    int curele = 0;
    int curw = INT_MAX;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i] && curw > wet[i])
        {
            curw = wet[i];
            curele = i;
        }
    }
    return curele;
}
void prims(int **g2d, int v)
{
    int *par = new int[v];
    int *wet = new int[v];
    bool *vis = new bool[v];
    for (int i = 0; i < v; i++)
    {
        par[i] = wet[i] = INT_MAX;
        vis[i] = false;
    }
    par[0] = -1;
    wet[0] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        int ele = minwele(wet, vis, v);
        for (int i = 0; i < v; i++)
        {
            if (ele != i && !vis[i] && g2d[ele][i] != 0)
            {
                int path = g2d[ele][i];
                if (wet[i] > path)
                {
                    wet[i] = path;
                    par[i] = ele;
                }
            }
        }
        vis[ele] = true;
    }

    for (int i = 1; i < v; i++)
    {
        cout << "\n"
             << i << " -- " << par[i] << " : " << wet[i];
    }

    delete[] par;
    delete[] wet;
    delete[] vis;
}

int main()
{
    int v, e;
    cin >> v >> e;
    int **g2d = new int *[v];
    for (int i = 0; i < v; i++)
    {
        g2d[i] = new int[v];
        for (int j = 0; j < v; j++)
            g2d[i][j] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cout << "\nEdge  " << i << " : ";
        cin >> s >> d >> w;
        g2d[s][d] = w;
        g2d[d][s] = w;
    }

    prims(g2d, v);

    for (int i = 0; i < v; i++)
        delete[] g2d[i];
    delete[] g2d;

    return 0;
}