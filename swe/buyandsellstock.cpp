#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    pair<int, int> p;
    p.first = prices[0];
    p.second = -1;
    int maxp = -1;
    for (int i = 1; i < prices.size(); i++)
    {
        int curp = prices[i];
        if (curp < p.first)
        {
            p.first = curp;
            p.second = -1;
        }
        else if (p.second == -1 || curp > p.second)
        {
            p.second = curp;
        }

        if (p.second != -1)
            maxp = max(maxp, p.second - p.first);
    }
    return maxp;
}