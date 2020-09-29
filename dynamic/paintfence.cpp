#include <bits/stdc++.h>

using namespace std;

int ways(int n, int k)
{
    vector<pair<int, int>> w(n);
    w[0].first = 0;
    w[0].second = k;

    for (int i = 1; i < n; i++)
    {
        w[i].first = w[i - 1].second;
        w[i].second = (w[i - 1].first + w[i - 1].second) * (k - 1);
    }

    return w[n - 1].first + w[n - 1].second;
}

int main()
{
    cout << ways(4, 3);
}