#include <bits/stdc++.h>

using namespace std;

unordered_map<int, list<int>> g;
unordered_map<int, bool> vis;
void dfs(int s, vector<int> &ans)
{
    // rec
    ans.push_back(s);
    for (int x : g[s])
        if (!vis[x])
        {
            vis[x] = true;
            dfs(x, ans);
        }
}

vector<vector<int>> coco()
{
    vector<vector<int>> ans;
    for (auto p : g)
    {
        if (!vis[p.first])
        {
            vis[p.first] = true;
            vector<int> getv;
            dfs(p.first, getv);
            ans.push_back(getv);
        }
    }
    return ans;
}


int main()
{
    freopen("perfectfriendsinput.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    g.clear();
    vis.clear();
    while (k != 0)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        k--;
    }

    vector<vector<int>> cc = coco();
    int total = 0;
    for (int i = 0; i < cc.size(); i++)
    {
        for (int j = i + 1; j < cc.size(); j++)
        {
            total += cc[i].size() * cc[j].size();
        }
    }
    cout << total;
}