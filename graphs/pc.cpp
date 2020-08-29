#include <bits/stdc++.h>

using namespace std;

class dsu
{
public:
    int v, e, *par, noc;
    dsu(int v, int e);
    ~dsu();
    int getp(int a);
    void dounion(int a, int b);
};

dsu::dsu(int v, int e) : v(v), e(e), noc(v)
{
    par = new int[v];
    for (int i = 0; i < v; i++)
        par[i] = i;
}

dsu::~dsu()
{
    delete[] par;
}

int dsu::getp(int a)
{
    // base
    if (par[a] == a)
        return a;
    // rec
    return par[a] = getp(par[a]);
}

void dsu::dounion(int a, int b)
{
    int apar = getp(a);
    int bpar = getp(b);
    if (apar != bpar)
    {
        par[apar] = bpar;
        noc--;
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
        g.dounion(a, b);
    }
    cout << g.getp(4);
    return 0;
}