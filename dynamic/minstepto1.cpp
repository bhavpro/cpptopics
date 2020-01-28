#include <iostream>
#include <limits.h>
#include <algorithm>

#define INF INT_MAX

using namespace std;

int arr[100];

int red(int n)
{

    // base

    arr[0] = INF;
    arr[1] = 0;

    if (n <= 1)
    {
        return arr[n];
    }

    // rec
    int a = n % 3 == 0 ? (arr[n / 3] != 0 ? arr[n / 3] : red(n / 3)) : INF;
    int b = n % 2 == 0 ? (arr[n / 2] != 0 ? arr[n / 2] : red(n / 2)) : INF;
    int c = arr[n - 1] != 0 ? arr[n - 1] : red(n - 1);
    arr[n] = min(a, min(b, c)) + 1;
    return arr[n];
}

int reddp(int n)
{
    // base
    int arr[100];
    arr[0] = INF;
    arr[1] = 0;

    int a, b;

    // rec
    for (int i = 2; i <= n; i++)
    {
        a = i % 2 == 0 ? arr[i / 2] : INF;
        b = i % 3 == 0 ? arr[i / 3] : INF;

        arr[i] = min(a, min(b, arr[i - 1])) + 1;
    }

    return arr[n];
}

int main()
{
    int n;
    cin >> n;
    cout << red(n) << "\n";
    cout << reddp(n);
    return 0;
}