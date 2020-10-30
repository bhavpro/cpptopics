#include <bits/stdc++.h>

using namespace std;

struct dsu
{
    int comp;
    vector<int> par;
    vector<int> rank;

    dsu(int n);
    int getsup(int a);
    void unionit(int a, int b);
};

dsu::dsu(int n)
{
    comp = n;
    par.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        rank[i] = 0;
    }
}
int dsu::getsup(int a)
{
    // base
    if (par[a] == a)
        return a;

    // rec
    return getsup(par[a]);
}

void dsu::unionit(int a, int b)
{
    int A = getsup(a);
    int B = getsup(b);
    if (A != B)
    {
        if (rank[A] > rank[B])
        {
            par[B] = A;
        }
        else if (rank[B] > rank[A])
        {
            par[A] = B;
        }
        else
        {
            par[B] = A;
            rank[A]++;
            rank[B] = 0;
        }
        comp--;
    }
}

int main()
{
}