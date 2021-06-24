#include <iostream>
#include <unordered_map>

using namespace std;

#define dist(x, y, a, b) abs((x) - (a)) + abs((y) - (b))

int minpath(int curx, int cury, int hx, int hy, int cx[], int cy[], int n, unordered_map<int, bool> &vis);

int bruteshort(int ox, int oy, int hx, int hy, int *cx, int *cy, int n)
{
    unordered_map<int, bool> vis;
    return minpath(ox, oy, hx, hy, cx, cy, n, vis);
}

int minpath(int curx, int cury, int hx, int hy, int cx[], int cy[], int n, unordered_map<int, bool> &vis)
{
    // base

    // rec
    bool allvis = true;
    int mindist = 1e9;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            allvis = false;
            vis[i] = true;
            mindist = min(mindist, dist(curx, cury, cx[i], cy[i]) + minpath(cx[i], cy[i], hx, hy, cx, cy, n, vis));
            vis[i] = false;
        }
    }

    // base
    if (allvis)
    {
        return dist(curx, cury, hx, hy);
    }
    return mindist;
}

int efficientshort(int ox, int oy, int hx, int hy, int *cx, int *cy, int n)
{
    unordered_map<int, bool> vis;
    int prex = ox, prey = oy;
    int adddist = 0;
    for (int i = 0; i < n; i++)
    {
        // get shortest node
        int mind = 1e9, mini;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j])
            {
                int oldmind = mind;
                mind = min(mind, dist(prex, prey, cx[j], cy[j]));
                if (mind != oldmind)
                    mini = j;
            }
        }

        // go to  that shortest node
        vis[mini] = true;
        adddist += dist(prex, prey, cx[mini], cy[mini]);
        prex = cx[mini];
        prey = cy[mini];
    }

    adddist += dist(hx, hy, prex, prey);
    return adddist;
}

int main()
{
    int n;
    cin >> n;
    int ox, oy, hx, hy;
    int *cx = new int[n], *cy = new int[n];
    cin >> ox >> oy >> hx >> hy;
    for (int i = 0; i < n; i++)
        cin >> cx[i] >> cy[i];

    // algo
    cout << bruteshort(ox, oy, hx, hy, cx, cy, n) << " " << efficientshort(ox, oy, hx, hy, cx, cy, n);

    delete[] cx;
    delete[] cy;
    return 0;
}