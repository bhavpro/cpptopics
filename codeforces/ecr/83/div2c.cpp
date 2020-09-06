#include <bits/stdc++.h>

using namespace std;

const int N = 1e16 + 1;

bool solve(int *a, int n, int k)
{
    long long p = 1;
    long long ma = 1e16 + 1;
    while (p < ma)
    {
        p = p * k;
    }

    while (p != 0)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] >= p)
            {
                a[j] = a[j] - p;
                break;
            }
        }
        p = p / k;
    }

    for (int j = 0; j < n; j++)
    {
        if (a[j] != 0)
        {
            return false;
        }
    }
    return true;
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
            cin >> a[i];
        cout << (solve(a, n, k) == false ? "NO\n" : "YES\n");
        delete[] a;
    }
}