#include <bits/stdc++.h>

using namespace std;

int nos(int n)
{
    int c = 0;
    while (n != 1)
    {
        if (n % 3 != 0)
        {
            return -1;
        }
        while (n % 6 == 0)
        {
            n /= 6;
            c++;
        }
        if (n % 3 == 0)
        {
            n *= 2;
            c++;
        }
    }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << nos(n) << "\n";
    }
    return 0;
}