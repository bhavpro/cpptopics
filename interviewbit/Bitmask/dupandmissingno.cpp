#include <bits/stdc++.h>

using namespace std;


vector<int> repeatedNumberop(const vector<int> &A)
{
    int n = A.size();
    int xorof1n = 0;
    int xorofarr = 0;
    long long sumofarr = 0, sumof1n = 0;
    for (int i = 1; i <= n; i++)
    {
        xorof1n ^= i;
        xorofarr ^= A[i - 1];
        sumof1n += i;
        sumofarr += A[i - 1];
    }

    int xorof2 = xorof1n ^ xorofarr;
    int mask;
    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        mask = 1 << i;
        if (mask & xorof2)
        {
            break;
        }
    }

    int tempxor = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mask & A[i - 1])
            tempxor ^= A[i - 1];
        if (mask & i)
            tempxor ^= i;
    }

    int num1 = tempxor;       // missing assume
    int num2 = num1 ^ xorof2; // dup assume

    if (sumof1n - sumofarr == num1 - num2)
    {
        return {num2, num1};
    }
    else
    {
        return {num1, num2};
    }
}