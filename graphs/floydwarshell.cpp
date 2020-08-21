#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

#define inf 1e9
#define getmin(a, b) a = min(a, b)

vector<vi> floyd(int v, int e, vector<vpi> adjl)
{
    vector<vi> ans(v + 1, vi(v + 1, inf));
    for (int i = 1; i <= v; i++)
    {
        ans[i][i] = 0;
        for (pii p : adjl[i])
        {
            ans[i][p.first] = p.second;
        }
    }

    // parse
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            for (int k = 1; k <= v; k++)
            {
                if (i == j || i == k)
                {
                    continue;
                }
                int tempdist = ans[j][i] + ans[i][k];
                getmin(ans[j][k], tempdist);
            }
        }
    }
    return ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int v, e;
    cin >> v >> e;
    vector<vpi> adjl(v + 1);
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        adjl[s].push_back({d, w});
    }
    vector<vi> ans = floyd(v, e, adjl);
    cout << "  ";
    for (int i = 1; i <= v; i++)
    {
        cout << i << " ";
    }
    cout << "\n";
    for (int i = 1; i < ans.size(); i++)
    {
        cout << i << " ";
        for (int j = 1; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}