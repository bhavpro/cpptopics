#include <bits/stdc++.h>

using namespace std;

struct dsu
{
    vector<int> par;
    int comp;
    void init(int n)
    {
        par.resize(n);
        comp = n;
        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
        }
    }

    int getsup(int x)
    {
        if (par[x] == x)
        {
            return x;
        }
        return par[x] = getsup(par[x]);
    }

    void unionit(int x, int y)
    {
        int gspx = getsup(x);
        int gspy = getsup(y);
        if (gspx != gspy)
        {
            par[x] = gspy;
            comp--;
        }
    }
};

int main()
{
    return 0;
}