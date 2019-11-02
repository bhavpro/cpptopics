#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define modulo (pow(10, 9) + 7)

int memo[100000];

int tileit(int n, int m)
{
    // base
    if(m > n)
    {
        return 1;
    }
    if(n == m)
    {
        return 2;
    }

    // rec
    int a, b;
    if(memo[n - m] == 0)
    {
        a = tileit(n - m, m);
    }
    else
    {
        a = memo[n - m];
    }

    if(memo[n - 1] == 0)
    {
        b = tileit(n - 1, m);
    }
    else
    {
        b = memo[n - 1];
    }

    long temp = (long)(a + b);
    temp =(long) temp % (long)modulo;
    memo[n] = temp;
    return temp;
}

int main()
{
    int t, n, m;
    cin >> t;
    while(t != 0)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            memo[i] = 0;
        }
        cout << tileit(n, m) << "\n";
        t--;
    }
    return 0;
}