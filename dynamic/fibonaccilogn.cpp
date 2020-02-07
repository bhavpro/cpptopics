#include <iostream>

using namespace std;

int fib(int m)
{
    // base
    if (m <= 1)
        return m;

    // rec
    int n = m - 1;
    if (n % 2 == 0)
    {
        int k = m / 2;
        int a = fib(k);
        int b = fib(k - 1);
        return a * a + b * b;
    }
    else
    {
        int k = n - 1;
        k /= 2;
        int a, b, c;
        a = fib(k);
        b = fib(k - 1);
        c = fib(k + 1);
        return a * (b + c);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n - 1);
    return 0;
}

// n-1 = 2k+1