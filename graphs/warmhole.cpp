#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class vertex
{
public:
    int x;
    int y;
    vertex()
    {
        x = -1;
        y = -1;
    }
    vertex(int x, int y) : x(x), y(y)
    {
    }
    void set(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    bool operator==(const vertex &v) const
    {
        if (x == v.x && y == v.y)
            return true;
        return false;
    }
};

int getmindist(int **g, bool *vis, int maxs, int cur)
{
    // base
    if (cur == 1)
        return 0;
    // rec
    vis[cur] = true;
    int mindist = 1e9 + 7;
    for (int i = 0; i < maxs; i++)
    {
        if (i != cur && !vis[i])
        {
            int dist = getmindist(g, vis, maxs, i) + g[cur][i];
            mindist = min(dist, mindist);
        }
    }
    vis[cur] = false;
    return mindist;
}

int main()
{
    vertex src;
    vertex dest;
    cin >> src.x >> src.y >> dest.x >> dest.y;
    int n;
    cin >> n;
    int maxs = (n << 1) + 2;
    vertex *arr = new vertex[maxs];
    int **g = new int *[maxs];
    for (int i = 0; i < maxs; i++)
    {
        g[i] = new int[maxs];
        for (int j = 0; j < maxs; j++)
            g[i][j] = -1;
    }
    arr[0].set(src.x, src.y);
    arr[1].set(dest.x, dest.y);
    int curs = 2;

    for (int i = 0; i < n; i++, curs += 2)
    {
        vertex temp1, temp2;
        int val;
        cin >> temp1.x >> temp1.y >> temp2.x >> temp2.y >> val;
        arr[curs] = temp1;
        arr[curs + 1] = temp2;
        g[curs][curs + 1] = g[curs + 1][curs] = val;
    }

    for (int i = 0; i < maxs; i += 2)
    {
        for (int j = 0; j < maxs; j++)
        {
            // dist from sources to others
            if (g[i][j] == -1)
                g[i][j] = abs(arr[i].x - arr[j].x) + abs(arr[i].y - arr[j].y);
            // dist from dest to others
            if (g[i + 1][j] == -1)
                g[i + 1][j] = abs(arr[i + 1].x - arr[j].x) + abs(arr[i + 1].y - arr[j].y);
        }
    }

    // finding distance
    bool *vis = new bool[maxs];
    for (int i = 0; i < maxs; i++)
        vis[i] = false;
    cout << getmindist(g, vis, maxs, 0);
    // #########

    delete[] arr;
    delete[] vis;
    for (int i = 0; i < maxs; i++)
        delete[] g[i];
    delete[] g;
    return 0;
}