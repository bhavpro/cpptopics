#include <bits/stdc++.h>

using namespace std;

int solve(int A)
{
    if (A <= 2)
        return A;
    if (A == 3)
        return 4;
    int mod = 1e9 + 7;
    long long curcount = 4;
    long long sum = 4;
    long long temp = 4; // temp store no of 1 in msb
    while ((temp << 1) - 1 <= A)
    {
        curcount = temp + sum;
        sum = (sum + curcount % mod) % mod;
        temp <<= 1;
    }
    for (int i = temp; i <= A; i++)
    {
        sum = (__builtin_popcount(i) + sum) % mod;
    }
    return sum;
}

int s1(int a)
{
    int sum = 0;
    for (int i = 1; i <= a; i++)
    {
        sum += __builtin_popcount(i);
    }
    return sum;
}

int soln(int a)
{
    if (a <= 1)
        return a;
    if (a <= 3)
        return a - 1;

    int mod = 1e9 + 7;
    long long ans = 4;
    long long till = 4;

    while (till <= a)
    {
        if (a < (till << 1))
            break;
        ans <<= 1;
        ans += till;
        ans %= mod;
        till <<= 1;
    }

    for (int i = till; i <= a; i++)
    {
        ans += __builtin_popcount(i);
        ans %= mod;
    }
    return ans;
}

int main()
{
    int a;
    cin >> a;
    cout << solve(a);
    cout << "\nans: " << s1(a);
}
