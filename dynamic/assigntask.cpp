#include <iostream>

using namespace std;

int n = 3;

int cost[3][3] = {{5, 3, 9}, {8, 4, 1}, {7, 2, 3}};

int ALL_DONE = (1 << n) - 1;

int minicost(int done, int cur)
{
    // base
    if (done == ALL_DONE)
        return 0;

    // rec
    int mincost = 9999999;
    for (int i = 0; i < n; i++)
    {
        int tempmask = (1 << i);
        if ((tempmask & done) == 0)
        {
            // do this task
            int curcost = cost[i][cur + 1] + minicost(done | tempmask, cur + 1);
            mincost = min(mincost, curcost);
        }
    }
    return mincost;
}

int main()
{
    // for (int i)
    int ans = 99999999;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, cost[0][i] + minicost(1 << i, 0));
    }
    cout << ans;
    return 0;
}