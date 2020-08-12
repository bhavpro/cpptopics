#include <iostream>
#include <climits>

#define INF INT_MAX

using namespace std;

int memo[100];

int nextpow2(int n)
{
    int i;
    for (i = 1; i < n; i *= 2)
    {
    }
    return i;
}

int cell(int n, int x, int y, int z)
{
    // base
    if (n == 1)
        return 0;

    // rec
    int a = INF, b = INF;
    a = n & 1 == 0 ? cell(n / 2, x, y, z) + x : INF; // divide by 2
    b = cell(n - 1, x, y, z) + y;                    // add 1
    memo[n] = min(a, b);
    int powerof2 = nextpow2(n);
    if (n / powerof2 != 1)
    {
        memo[powerof2] = memo[powerof2 / 2] + x;
        for (int i = powerof2 - 1; i >= n; i++)
        {
            int c = INF;
            if (i & 1 == 0)
            {
                c = memo[i / 2] + x;
            }
            memo[i] = min(c, memo[i + 1] + z);
        }
        memo[n] = min(memo[n], memo[n + 1] + z);
    }
    return memo[n];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 30; i++)
    {
        memo[i] = INF;
    }
    cout << cell(5, 2, 3, 4);
    return 0;
}