#include <iostream>
#include <string>
#include <unordered_map>
#include <list>

using namespace std;

struct dsu
{
    int cc;
    unordered_map<char, char> par;
    dsu(int n, char *a, int len)
    {
        cc = n;
        for (int i = 0; i < len; i++)
            par[a[i]] = a[i];
    }
    ~dsu()
    {
    }
    char getp(char x)
    {
        if (par[x] == x)
            return x;
        return par[x] = getp(par[x]);
    }
    bool issamecomp(char a, char b)
    {
        return getp(a) == getp(b);
    }
    void unionit(char a, char b)
    {
        if (!issamecomp(a, b))
        {
            char pa = getp(a);
            char pb = getp(b);
            par[pa] = pb;
        }
    }
};

bool isperm(char *a, char *b, int len, char **swaparr, int n)
{
    // make a graph from swaparr
    dsu g(n, a, len);
    for (int i = 0; i < n; i++)
    {
        char x = swaparr[i][0];
        char y = swaparr[i][1];
        g.unionit(x, y);
    }

    for (int i = 0; i < len; i++)
    {
        char x = a[i];
        char y = b[i];
        if (!g.issamecomp(x, y))
            return false;
    }
    return true;
}

int main()
{
    int len;
    cin >> len;
    char a[1000], b[1000];
    cin >> a >> b;
    int n;
    cin >> n;
    char **swaparr = new char *[n];
    for (int i = 0; i < n; i++)
    {
        swaparr[i] = new char[2];
        cin >> swaparr[i];
    }

    cout << (isperm(a, b, len, swaparr, n) == true ? "true" : "false");

    for (int i = 0; i < n; i++)
        delete[] swaparr[i];
    delete[] swaparr;

    return 0;
}