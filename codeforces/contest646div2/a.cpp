#include <bits/stdc++.h>

using namespace std;

bool solve(int *a, int n, int x, int no, int ne)
{
    if (no == 0)
        return false;
    if (n < x)
        return false;

    // insert an odd at end
    no--;
    x--;

    // insert evens now
    x -= ne;
    ne = 0;
    if (x <= 0)
    {
        return true;
    }
    if (x % 2 == 0)
    {
        if (no >= x)
        {
            return true;
        }
    }
    if (no >= x + 1)
    {
        return true;
    }
    return false;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int *a = new int[n];
        int no = 0, ne = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] & 1)
                no++;
            else
                ne++;
        }
        cout << (solve(a, n, x, no, ne) == 1 ? "Yes" : "No") << "\n";
        delete[] a;
    }
    return 0;
}