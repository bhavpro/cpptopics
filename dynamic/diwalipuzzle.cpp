#include <iostream>
#include <vector>

#define mod 1000003

using namespace std;

int memo[100][2][105];

int bulb(int n, int k, int i = 0, int prev = -1, int count = 0)
{
    // base
    if (i == n)
    {
        return count == k ? 1 : 0;
    }

    // rec

    if (i == 0)
    {
        memo[i][prev][count] = (bulb(n, k, i + 1, 0, 0) + bulb(n, k, i + 1, 1, 0)) % mod;
        return memo[i][prev][count];
    }

    if (memo[i][prev][count] != -1)
    {
        return memo[i][prev][count];
    }

    if (prev == 0)
    {
        memo[i][prev][count] = (bulb(n, k, i + 1, 0, count) + bulb(n, k, i + 1, 1, count)) % mod;
        return memo[i][prev][count];
    }

    memo[i][prev][count] = (bulb(n, k, i + 1, 0, count) + bulb(n, k, i + 1, 1, count + 1)) % mod;
    return memo[i][prev][count];
}

int main()
{
    int n, k;
    cin >> n;
    cin >> k;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 105; j++)
        {
            memo[i][0][j] = -1;
            memo[i][1][j] = -1;
        }
    }

    cout << bulb(n, k);
    return 0;
}