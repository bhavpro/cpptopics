#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, *a;
        cin >> n >> x;
        a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int c = 0;
        int tc = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            tc++;
            if (a[i] * tc >= x)
            {
                c++;
                tc = 0;
            }
        }
        cout << c << "\n";
        delete[] a;
    }
    return 0;
}