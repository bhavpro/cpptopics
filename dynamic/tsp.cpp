#include <iostream>
#include <climits>

using namespace std;

int n = 4;

int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 30, 0, 10},
    {25, 34, 10, 0}};

int ALL_VISITED = (1 << n) - 1;

int memo[16][4];

int tsp(int mask, int pos)
{
    // if visited all cities
    if (mask == ALL_VISITED)
        return dist[pos][0];

    // check for unvisited city
    int minans = 9999999;
    for (int i = 0; i < n; i++)
    {
        int tempmask = (1 << i);
        bool vis = (mask & tempmask);
        if (!vis)
        {
            int newmask = mask | tempmask;
            int newans = dist[pos][i] + (memo[newmask][i] == -1 ? tsp(newmask, i) : memo[newmask][i]);
            minans = min(minans, newans);
        }
    }
    return memo[mask][pos] = minans;
}

int main()
{
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            memo[i][j] = -1;

    int ans = tsp(1, 0);
    cout << ans;
    return 0;
}