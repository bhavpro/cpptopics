#include <bits/stdc++.h>

using namespace std;

int isit(int *a, int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i - 1] < a[i] && a[i] > a[i + 1])
        {
            return i;
        }
    }
    return -1;
}

int main()
{
  //  freopen("input.txt", "r", stdin);
    int t, n, *a;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int a2 = isit(a, n);
        cout << (a2 == -1 ? "NO" : "YES") << "\n";
        if (a2 != -1)
        {
            cout << a2  << " " << a2 +1<< " " << a2 + 2;
        }
        cout << "\n";
        delete[] a;
    }
    return 0;
}