#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

vector<int> getdfspath(const unordered_map<int, list<int>> &g, unordered_map<int, bool> &vis, int s, int d)
{
    vector<int> ans;
    // base
    if (s == d)
    {
        ans.push_back(s);
        return ans;
    }
    // rec
    list<int> ll = g.at(s);
    vis[s] = true;
    for (int ch : ll)
    {
        if (!vis[ch])
        {
            // visit child
            vector<int> temp = getdfspath(g, vis, ch, d);
            if (!temp.empty())
            {
                // dest found
                temp.push_back(s);
                return temp;
            }
        }
    }

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
    cin >> u >> v;
    unordered_map<int, bool> vis;
    vector<int> ans = getdfspath(g, vis, u, v);
    if (ans.empty())
        cout << "\nDest Not Found";
    else
    {
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " --> ";
    }
    return 0;
}