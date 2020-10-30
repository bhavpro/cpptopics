#include <bits/stdc++.h>

using namespace std;

struct dsu
{
    int comp;
    vector<int> par;
    vector<int> size;

    dsu(int n);
    int getsup(int a);
    void unionit(int a, int b);
};

dsu::dsu(int n)
{
    comp = n;
    par.resize(n);
    size.reserve(n);
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        size[i] = 1;
    }
}

int dsu::getsup(int a)
{
    // base
    if (par[a] == a)
        return a;
    // rec
    return par[a] = getsup(par[a]);
}

void dsu::unionit(int a, int b)
{
    int pa = getsup(a);
    int pb = getsup(b);
    if (pa != pb)
    {
        par[pa] = pb;
        size[pb] += size[pa];
        size[pa] = 0;
        comp--;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    dsu g(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g.unionit(a, b);
    }
    
    //

    vector<int> comp;
    for (int i = 0; i < n; i++)
    {
        if (g.par[i] == i)
            comp.push_back(g.size[i]);
    }
    //
    int ans = 0;
    for (int i = 0; i < comp.size() - 1; i++)
        for (int j = i + 1; j < comp.size(); j++)
            ans += comp[i] * comp[j];
    if (comp.size() == 1)
        return comp[0];
    return ans;
}