#include <bits/stdc++.h>

using namespace std;

int lp(vector<vector<int>> &g, unordered_map<int, int> &len, int cur)
{
    int length = 0;
    for (int ch : g[cur])
    {
        if (!len[ch])
        {
            int nl = lp(g, len, ch) + 1;
            length = max(length, nl);
        }
        else
        {
            length = max(length, len[ch] + 1);
        }
    }
    len[cur] = length;
    return length;
}

int rec(vector<vector<int>> &g)
{
    int lnst = 0;
    unordered_map<int, int> len;
    for (int i = 1; i < g.size(); i++)
    {
        if (!len[i])
            lnst = max(lnst, lp(g, len, i));
    }
    return lnst;
}

int main()
{
   // freopen("gin.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    cout << rec(g);
    return 0;
}