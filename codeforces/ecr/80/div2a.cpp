#include <bits/stdc++.h>

using namespace std;

bool cando(int n, int d)
{
    int x = 0;
    while ((x + ceil((double)d / (x + 1))) > n && x <= n)
    {
        if (x == n)
            return false;
        x++;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        cout << (cando(n, d) == 1 ? "YES" : "NO") << "\n";
    }
    return 0;
}