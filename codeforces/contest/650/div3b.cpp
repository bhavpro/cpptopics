#include <bits/stdc++.h>

using namespace std;

int findmin(int *a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & 1) != (i & 1))
            count++;
    }
    if (count & 1)
        return -1;
    else
        return (count >> 1);
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, *a;
        cin >> n;
        a = new int[n];

        int odd = 0, even = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] & 1)
                odd++;
            else
                even++;
        }

        if (odd == even && !(n & 1) || (n & 1) && odd + 1 == even)
            cout << findmin(a, n) << "\n";
        else
            cout << "-1\n";
        delete[] a;
    }
    return 0;
}