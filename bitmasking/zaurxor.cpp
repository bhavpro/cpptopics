#include <bits/stdc++.h>

using namespace std;

int zaur(vector<int> a, int k, int m)
{
    if (k & 1) // odd k
    {
        int xorr = 0;
        for (int i = 0; i < k; i++)
        {
            xorr = xorr ^ a[m + i];
        }
        return xorr;
    }
    return a[m] ^ a[m + k];
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n);
    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    cout << zaur(a, k, m);
    return 0;
}