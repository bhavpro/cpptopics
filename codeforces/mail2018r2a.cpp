#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 2;

bool abletoreach(bitset<N> f, bitset<N> b, int n, int s)
{
    if (f[s] != 1 && b[s] != 1 || f[1] == 0)
    {
        return false;
    }
    int i = 1;
    for (; i <= n; i++)
    {
        if (i == s && f[i] == 1)
        {
            return true;
        }
        if (i > s && f[i] == 1 && b[i] == 1)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, s;
    cin >> n >> s;
    bitset<N> f, b;
    bool temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        f[i] = temp;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        b[i] = temp;
    }
    cout << (abletoreach(f, b, n, s) == true ? "YES" : "NO");
    return 0;
}