#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    if (k == 1)
        cout << n;
    else
    {
        long long nob = 0, maxp = n;
        if (n == 0)
            nob = 1;
        else
            while (maxp != 0)
            {
                maxp >>= 1;
                nob++;
            }

        maxp = (1LL << nob) - 1;
        cout << maxp;
    }
    return 0;
}