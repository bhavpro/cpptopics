#include <bits/stdc++.h>

using namespace std;

int main()
{
   // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    int a = 6, b = 10, c = 14;
    int sum = a + b + c;
    while (t--)
    {
        int n;
        cin >> n;
        int no4 = n - sum;
        if (no4 > 0 && no4 != a && no4 != b && no4 != c)
        {
            cout << "YES\n";
            cout << a << " " << b << " " << c << " " << no4 << " \n";
        }
        else
        {
            if (n == 36)
            {
                cout << "YES\n";
                cout << 6 << " " << 10 << " " << 15 << " " << 5 << "\n";
            }
            else if (n == 40)
            {
                cout << "YES\n";
                cout << 6 << " " << 10 << " " << 15 << " " << 9 << " \n";
            }
            else if (n == 44)
            {
                cout << "YES\n";
                cout << 6 << " " << 7 << " " << 10 << " " << 21 << " \n";
            }
            else
            {
                cout << "NO \n";
            }
        }
    }
    return 0;
}