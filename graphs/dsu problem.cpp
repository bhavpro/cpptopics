#include <bits/stdc++.h>

using namespace std;

struct dsu
{
    vector<int> par;
    vector<int> size;
    int comp;

    void init(int n)
    {
        comp = n;
        par.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
            size[i] = 1;
        }
    }

    void unionit(int x, int y)
    {
        int xpar = getp(x);
        int ypar = getp(y);
        if (xpar != ypar)
        {
            par[x] = ypar;
            size[ypar] = size[ypar] + size[xpar];
            size[xpar] = 0;
            comp--;
        }
    }

    int getp(int x)
    {
        // base
        if (par[x] == x)
        {
            return x;
        }
        // rec
        return par[x] = getp(par[x]);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    dsu g;
    g.init(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g.unionit(x, y);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (n - g.size[g.getp(i)]);
    }
    cout << (ans / 2);
    return 0;
}