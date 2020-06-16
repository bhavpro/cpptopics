#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

ll arr[50];

ll recfib(int n)
{
    // base
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }

    // rec
    return recfib(n - 1) + recfib(n - 2);
}

ll topdown(int n)
{
    // base
    if (n == 1)
    {
        arr[1] = 1;
        return arr[1];
    }
    if (n == 0)
    {
        arr[0] = 0;
        return arr[0];
    }

    // rec
    if (arr[n - 2] == -1)
    {
        arr[n - 2] = topdown(n - 2);
    }

    if (arr[n - 1] == -1)
    {
        arr[n - 1] = topdown(n - 1);
    }

    return topdown(n - 1) + topdown(n - 2);
}

ll bottomup(int n)
{
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}

ll spaceopt(int n)
{
    ll a, b, c;
    a = 0;
    b = 1;
    c = 1;
    if (n <= 1)
    {
        return n;
    }

    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
//*********************************************************

void multiply(int a[2][2], int b[2][1])
{
    int c[2][1];
    for (int i = 0; i < 2; i++)
    {
        int sum = 0;
        for (int k = 0; k < 2; k++)
        {
            sum += a[i][k] * b[k][0];
        }
        c[i][0] = sum;
    }
    for (int i = 0; i < 2; i++)
    {
        b[i][0] = c[i][0];
    }
}

void multiply22(int a[2][2], int b[2][2], int c[2][2])
{
    for (int i = 0; i < 2; i++) // choose row 1 mat 1
    {
        for (int j = 0; j < 2; j++) // choose col 1 of mat 2
        {
            int sum = 0;
            for (int k = 0; k < 2; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}

void power(int arr[2][2], int n, int ans[2][2])
{
    // base
    if (n == 1)
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                ans[i][j] = arr[i][j];
        return;
    }

    if (n == 0)
    {
        ans[0][0] = 1;
        ans[0][1] = 0;
        ans[1][0] = 0;
        ans[1][1] = 1;
        return;
    }

    // rec
    int a[2][2];
    power(arr, n / 2, a);
    multiply22(a, a, ans);

    if (n & 1 == 1)
    {
        multiply22(arr, ans, a);
        // copy a to ans
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                ans[i][j] = a[i][j];
    }
}

int matrixexp(int n)
{
    int T[2][2];
    T[0][0] = 1;
    T[0][1] = 1;
    T[1][0] = 1;
    T[1][1] = 0;

    int base[2][1];
    base[0][0] = 1;
    base[1][0] = 0;
    int ans[2][2];
    power(T, n - 1, ans);
    multiply(ans, base);
    return base[0][0];
}

int main()
{
    int n;
    cin >> n;
    memset(arr, -1, 20);
    cout << matrixexp(n) << "\n"
         << flush; // O(log(n))
    cout << spaceopt(n) << "\n"
         << flush; // O(n) time , O(1) space
    cout << bottomup(n) << "\n"
         << flush; // O(n)
    cout << topdown(n) << "\n"
         << flush; // O(n)
    cout << recfib(n) << "\n"
         << flush; // O(2^n)
    return 0;
}