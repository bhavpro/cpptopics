#include <bits/stdc++.h>

using namespace std;

#define max3(x, y, z) ::max(::max((x), (y)), (z))
#define min3(x, y, z) ::min(::min((x), (y)), (z))

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int a, b, c;
    int x[3];
    while (t--)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> x[i];
        }
        sort(x, x + 3);

        if (x[1] == x[2])
        {
            cout << "YES\n ";
        }
        else
        {
            cout << "NO\n";
            continue;
        }
        c = x[2];
        b = x[0];
        a = x[0];
        cout << a << " " << b << " " << c << "\n";
    }
    return 0;
}