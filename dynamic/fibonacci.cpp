#include <iostream>

using namespace std;

int fib(int n)
{
    int *arr = new int[n + 1];
    // base
    arr[0] = 0;
    arr[1] = 1;

    // rec
    int i = 0;
    for (i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    int x = arr[i - 1];
    delete[] arr;
    return x;
}

int fibspaceop(int n)
{
    // base
    if (n <= 1)
    {
        return n;
    }

    int a, b;
    a = 0;
    b = 1;
    int c;

    // rec
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main()
{
    int n;
    cin >> n;
    cout << fibspaceop(n);
    return 0;
}
