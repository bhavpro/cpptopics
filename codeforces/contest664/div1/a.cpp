#include <bits/stdc++.h>

using namespace std;

int rec(int *a, int n, int d, int m, int i, int dcur)
{
    // base
    if (i == n)
    {
        return 0;
    }

    // rec
    int ans1 = 0; //chat
    int ans2 = 0; //not chat
    if (dcur == 0)
    {
        if (a[i] > m)
            ans1 = rec(a, n, d, m, i + 1, d);
        else
            ans1 = rec(a, n, d, m, i + 1, 0);
    }
    ans2 = rec(a, n, d, m, i + 1, (dcur != 0 ? dcur - 1 : 0));
    return max(ans2, ans1 + a[i]);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, d, m;
    cin >> n >> d >> m;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << rec(a, n, d, m, 0, 0);
    delete[] a;
    return 0;
}