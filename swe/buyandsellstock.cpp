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

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> minprice(n), maxprice(n);
    int minval = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minval = min(minval, prices[i]);
        minprice[i] = minval;
    }
    int maxval = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        maxval = max(maxval, prices[i]);
        maxprice[i] = maxval;
    }

    int diff = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int temp = maxprice[i] - minprice[i];
        if (temp >= 0)
            diff = max(diff, temp);
    }

    return diff;
}