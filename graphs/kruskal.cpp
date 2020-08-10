#include <bits/stdc++.h>

using namespace std;

struct edge
{
    int s;
    int e;
    int w;
};

struct Set
{
    int par;
    int rank;
};

int findp(vector<Set> &s, int i)
{
    int par = s[i].par;
    if (par == i)
    {
        return i;
    }

    return s[i].par = findp(s, par);
}

void Union(vector<Set> &s, int a, int b)
{
    int apar = findp(s, a);
    int bpar = findp(s, b);
    if (apar == bpar)
    {
        return;
    }
    int ra = s[apar].rank;
    int rb = s[bpar].rank;
    if (ra < rb)
    {
        s[apar].par = bpar;
        s[apar].rank = 0;
    }
    else if (ra > rb)
    {
        s[bpar].par = apar;
        s[bpar].rank = 0;
    }
    else
    {
        s[bpar].par = apar;
        s[bpar].rank = 0;
        s[apar].rank++;
    }
}

bool sortit(const edge &a, const edge &b)
{
    if (a.w < b.w)
        return true;
    return false;
}

void kruskal(vector<edge> &e, int n)
{
    int m = e.size();
    sort(e.begin(), e.end(), sortit);
    vector<edge> out;
    vector<Set> s(n);
    for (int i = 0; i < n; i++)
    {
        s[i].rank = 0;
        s[i].par = i;
    }
    for (int i = 0; i < m; i++)
    {
        int sp, ep;
        sp = findp(s, e[i].s);
        ep = findp(s, e[i].e);
        if (sp == ep)
            continue;
        Union(s, sp, ep);
        out.push_back(e[i]);
    }
    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i].s << " --> " << out[i].e << " : " << out[i].w << "\n";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<edge> e;
    for (int i = 0; i < m; i++)
    {
        edge temp;
        cin >> temp.s >> temp.e >> temp.w;
        e.push_back(temp);
    }
    kruskal(e, n);
}