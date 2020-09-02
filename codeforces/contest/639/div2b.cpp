#include <bits/stdc++.h>

using namespace std;

vector<int> noc;

void fillnoc()
{
    noc.push_back(0);
    long long nc = 2;
    int half = 2;
    long long full = 0;
    while (nc <= 1e9)
    {
        noc.push_back(nc);
        nc += ++full * 3;
        nc += half;
    }
}

void fillnoc1()
{
    int i = 0;
    long long nc = 0;
    while (nc <= 1e9)
    {
        nc = (i * i * 3 + i) >> 1;
        noc.push_back(nc);
        i++;
    }
}

int nop(int n)
{
    int count = 0;
    while (n >= 2)
    {
        auto ptr = upper_bound(noc.begin(), noc.end(), n);
        ptr--;
        n -= *ptr;
        count++;
    }
    return count;
}

int main()
{
    fillnoc1();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << nop(n) << "\n";
    }
    return 0;
}