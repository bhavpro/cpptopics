#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int c = 0;
        int a, b, n;
        cin >> a >> b >> n;
        while (a <= n && b <= n)
        {
            c++;
            if (a < b)
            {
                a += b;
            }
            else
            {
                b += a;
            }
        }
        cout << c << "\n";
    }
    return 0;
}