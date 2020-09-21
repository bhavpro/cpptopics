#include <bits/stdc++.h>
using namespace std;

#define loop(a, b) for (int i = a; i <= b; i++)

int toys(int *a, int n, int k)
{
    int count = 0;
    sort(a, a + n);
    loop(0, n - 1)
    {
        k -= a[i];
        if (k >= 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
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
        loop(0, n - 1)
        {
            cin >> a[i];
        }
        cout << toys(a, n, k) << "\n";
        delete[] a;
    }
    return 0;
}