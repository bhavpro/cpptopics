#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[abs(a[i])] > 0)
        {
            a[abs(a[i])] = -a[abs(a[i])];
        }
        else
        {
            cout << abs(a[i]) << " ";
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    solve(a, n);
    delete[] a;
    return 0;
}