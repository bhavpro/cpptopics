#include <bits/stdc++.h>

using namespace std;

class dsu
{
public:
    int v, e, *par;
    bool cycle;
    dsu(int v, int e);
    ~dsu();
    void unit(int a, int b);
    int getpar(int a);
    bool iscyclic()
    {
        return cycle;
    }
};

dsu::dsu(int v, int e)
{
    this->v = v;
    this->e = e;
    par = new int[v + 1];
    for (int i = 1; i <= v; i++)
    {
        par[i] = i;
    }
    cycle = false;
}

dsu::~dsu()
{
    delete[] par;
}

int dsu::getpar(int a)
{
    if (par[a] == a)
        return a;
    return getpar(par[a]);
}

void dsu::unit(int a, int b)
{
    int apar = getpar(a);
    int bpar = getpar(b);
    if (apar == bpar)
    {
        cycle = true;
    }
    else
    {
        par[apar] = bpar;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int v, e;
    cin >> v >> e;
    dsu g(v, e);
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        g.unit(a, b);
    }
    cout << g.iscyclic();
    return 0;
}