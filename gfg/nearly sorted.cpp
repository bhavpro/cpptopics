#include <bits/stdc++.h>

using namespace std;

void solve(int *a, int n, int k)
{
    sort(a, a + n);
}

void solve2(int *a, int n, int k)
{
    for (int i = 0; i < max(n - k, 0); i++)
    {
        sort(a + i, a + i + k + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        solve2(a, n, k);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}