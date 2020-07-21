#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define ll long long
#define pb push_back

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); /*
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE*/
}

const int N = 1000005;
vector<ll> g[N];
int disc[N], low[N], t;
vector<int> ap;
vector<pair<int, int>> bridge;

void discdfs(int nod, int par)
{
    int noofchild = 0;
    // base

    // rec
    t++;
    disc[nod] = t;
    low[nod] = t;
    for (int child : g[nod])
    {
        if (disc[child] == 0) // not visited child
        {
            noofchild++;
            discdfs(child, nod);
            low[nod] = min(low[nod], low[child]);
            if (par != 0 && low[child] >= disc[nod])
            {
                ap.push_back(nod);
            }
            if (low[child] > disc[nod])
            {
                bridge.pb(make_pair(nod, child));
            }
        }
        else if (child != par) // back edge
        {
            low[nod] = min(low[nod], low[child]);
        }
    }

    if (par == 0 && noofchild >= 2)
    {
        ap.push_back(par);
    }
}

void solve()
{
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    t = 0;
    discdfs(1, 0);
    cout << "----\n";
    for (int x : ap)
        cout << x << " ";
    cout << ap.size();
    cout << "\n----";
}

int main()
{
    // init();
    solve();
}