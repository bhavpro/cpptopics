#include <bits/stdc++.h>

using namespace std;

vector<int> repeatedNumber(const vector<int> &A)
{
    int n = A.size();
    int xorof2 = 0;
    long long sumarr = 0, sum1ton = 0;

    for (int i = 0; i < A.size(); i++)
    {
        xorof2 ^= A[i];
        sumarr += A[i]
    }
    for (int i = 1; i <= n; i++)
    {
        xorof2 ^= i;
        sum1ton += A[i];
    }
    int temp = xorof2;
    int distinctbit = 0;
    while (temp != 0)
    {
        if (temp & 1)
            break;
        distinctbit++;
        temp >>= 1;
    }

    int xordb1 = 0, xordb0 = 0;
    for (int i = 0; i < A.size(); i++)
        if (A[i] & (1 << distinctbit))
            xordb1 ^= A[i];
        else
            xordb0 ^= A[i];

    for (int i = 1; i <= n; i++)
        if (A[i] & (1 << distinctbit))
            xordb1 ^= A[i];
        else
            xordb0 ^= A[i];

    int num1 = xordb0 ^ xorof2;
    int num2 = xordb1 ^ xorof2;

    if (sumarr - sum1ton != num1 - num2)
    {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    return vector<int>({num1, num2});
}