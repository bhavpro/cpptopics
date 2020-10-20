#include <bits/stdc++.h>

using namespace std;

int maxprice(multimap<int, pair<int, int>> sched, int n)
{
    vector<int> dp(n + 1);

    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
            return 0;
        else
        {
            dp[i] = dp[i - 1];
            auto itr = sched.equal_range(i);
            while (itr.first != itr.second)
            {
                pair<int, int> val = itr.first->second;
                dp[i] = max(dp[i], dp[val.first - 1] + val.second);
                itr.first++;
            }
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    multimap<int, pair<int, int>> ma;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        pair<int, pair<int, int>> temp = make_pair(b, make_pair(a, c));
        ma.insert(temp);
    }

    cout << maxprice(ma, n);
}