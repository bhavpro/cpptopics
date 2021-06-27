#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> visitit(const unordered_map<int, list<int>> &g, unordered_map<int, bool> &vis, int s)
{
    // base

    // rec
    vector<int> ans;
    vis[s] = true;
    for (int ch : g.at(s))
        if (!vis[ch])
        {
            vector<int> temp = visitit(g, vis, ch);
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
    ans.push_back(s);
    return ans;
}

vector<vector<int>> conncomp(const unordered_map<int, list<int>> &g)
{
    vector<vector<int>> ans;
    unordered_map<int, bool> vis;
    for (pair<int, list<int>> p : g)
        if (!vis[p.first])
            // visit it
            ans.push_back(visitit(g, vis, p.first));

    return ans;
}

int main()
{
    unordered_map<int, list<int>> g;
    int noe;
    cin >> noe;
    int u, v;
    for (int i = 0; i < noe; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> ans = conncomp(g);
    for (vector<int> v : ans)
    {
        cout << "\n\n";
        for (int x : v)
        {
            cout << x << " ";
        }
    }
    return 0;
}