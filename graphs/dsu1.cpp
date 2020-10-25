#include <bits/stdc++.h>

using namespace std;

struct dsu
{
    int comp;
    vector<int> par;

    dsu(int n);
    int getsup(int a);
    void unionit(int a, int b);
};

dsu::dsu(int n)
{
    comp = n;
    par.resize(n);
    for (int i = 0; i < n; i++)
        par[i] = i;
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
    int A = getsup(a);
    int B = getsup(b);
    if (A != B)
    {
        par[A] = B;
        comp--;
    }
}

int main()
{
}