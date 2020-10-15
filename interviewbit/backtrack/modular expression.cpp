#include <bits/stdc++.h>

using namespace std;

int rec(int A, int B, int C)
{
    // base
    if (B == 0)
        return 1;

    if (B == 1)
        return A;

    // rec
    long long x = rec(A, B >> 1, C);
    x = (x * x) % C;
    if (B & 1)
        x *= A;
    return x % C;
}

int Mod(int A, int B, int C)
{
    if (A == 0)
        return 0;
    if (A == 1)
        return 1;
    return rec(((A % C) + C) % C, B, C);
}