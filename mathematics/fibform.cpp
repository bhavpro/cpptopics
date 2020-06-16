#include <iostream>

using namespace std;

int fib(int n)
{
    // base
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 1;
    }
    // rec
    int k = n / 2;
    //cout << n << flush;
    if (n % 2 == 0)
    {
        int a = fib(k);
        int b = fib(k - 1);
        return a * a + b * b;
    }
    int a = fib(k);
    int b = fib(k + 1);
    int c = fib(k - 1);
    return a * b + a * c;
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}