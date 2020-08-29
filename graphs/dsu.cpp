#include <bits/stdc++.h>

using namespace std;

#define loop(n) for (int i = 0; i < n; i++)

class dsu
{
public:
    int v, e;
    int *parent;
    dsu(int v, int e);
    ~dsu();
    void dounion(int a, int b);
    int getp(int a);
};

dsu::dsu(int v, int e)
{
    this->e = e;
    this->v = v;
    parent = new int[v + 1];
    loop(v)
        parent[i] = i;
}

dsu::~dsu()
{
    delete[] parent;
}

int dsu::getp(int a)
{
    // base
    if (parent[a] == a)
        return a;
    // rec
    return getp(parent[a]);
}

void dsu::dounion(int a, int b)
{
    int apar = getp(a);
    int bpar = getp(b);
    if (apar != bpar)
    {
        parent[apar] = bpar;
    }
}

int main()
{
    int v, e;
    cin >> v >> e;

    return 0;
}