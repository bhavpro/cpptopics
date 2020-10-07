#include <bits/stdc++.h>

using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int p1 = days[0], p2 = days[1], p3 = days[2];
    int n = costs.size();
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1] = 0;
        int day = days[i];
        
    }
}