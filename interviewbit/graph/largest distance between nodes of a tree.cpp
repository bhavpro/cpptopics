#include <bits/stdc++.h>

using namespace std;

pair<int, int> dfs(vector<vector<int>> &g, int cur, int par)
{
    // base

    // rec
    vector<pair<int, int>> arr;
    for (int ch : g[cur])
    {
        if (ch != par)
        {
            arr.push_back(dfs(g, ch, cur));
        }
    }

    // base
    if (arr.empty())
        return {1, 1};

    if (arr.size() <= 1)
        return {arr[0].first + 1, max(arr[0].second, arr[0].first + 1)};

    // rec
    pair<int, int> p, ans;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            p.first = max(arr[i].first, arr[j].first);
            p.second = max(max(arr[i].second, arr[j].second), arr[i].first + arr[j].first);
            ans.first = max(ans.first, p.first);
            ans.second = max(ans.second, p.second);
        }
    }
    return {ans.first + 1, ans.second};
}

int solve(vector<int> &A)
{
    int n = A.size();
    if (n <= 1)
        return 0;
    vector<vector<int>> g(n);
    int par = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != -1)
        {
            g[i].push_back(A[i]);
            g[A[i]].push_back(i);
        }
        else
            par = i;
    }

    pair<int, int> p = dfs(g, par, -1);
    return p.second;
}
