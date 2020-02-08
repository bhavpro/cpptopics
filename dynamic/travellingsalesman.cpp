#include <iostream>
#include <bitset>
#include <limits.h>
#include <algorithm>

using namespace std;

int n = 4;

int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}};

int allvisited = (1 << n) - 1;

int anstravel(bitset<4> a, int prev = -1, int base = -1)
{
    // base
    if (a.to_ulong() == allvisited)
    {
        return dist[prev][base];
    }

    // rec
    int mincost = INT_MAX;
    int temp = 0;
    bool addcost = true;
    if (a.to_ulong() == 0)
    {
        addcost = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            a.set(i);

            temp = base == -1 ? anstravel(a, i, i) : anstravel(a, i, base);
            if (addcost == true)
            {
                temp += dist[prev][i];
            }
            a.reset(i);
            mincost = min(temp, mincost);
        }
    }
    return mincost;
}

int memo[16][4];

int tsp(int mask, int prev)
{
    // base
    if (mask == allvisited)
    {
        return dist[prev][0];
    }

    // rec
    int ans = 9999999;
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0) // city not visited
        {
            // now we will visit the city
            int newmask = mask | (1 << city);
            int newans = dist[prev][city] + (memo[newmask][city] == 0 ? tsp(newmask, city) : memo[newmask][city]);
            ans = min(newans, ans);
        }
    }
    memo[mask][prev] = ans;
    return ans;
}

int main()
{
    bitset<4> a;
    a.reset();
    cout << anstravel(a);
    cout << "\n"
         << tsp(1, 0);
    return 0;
}