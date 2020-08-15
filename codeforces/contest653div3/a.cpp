#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, n;
        cin >> x >> y >> n;
        int k = n - (n % x) + y;
        while (k > n)
        {
            k = k - x;
        }
        cout << k << "\n";
    }
}