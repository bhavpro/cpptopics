#include <bits/stdc++.h>

using namespace std;

int divide(int A, int B)
{
    long long count = 0;
    long long a = A;
    long long b = B;
    int i = 31;
    if (b == 0)
        return INT_MAX;

    bool neg = false;
    if (a < 0)
    {
        neg = !neg;
        a = -a;
    }
    if (B < 0)
    {
        neg = !neg;
        b = -b;
    }
    if (b == 1)
    {
        count = a;
    }
    else
        while (a >= b)
        {
            long long tb = (b << i);
            if (a > tb)
            {
                a = a - tb;
                count += (i << i);
            }
        }
    if (count > INT_MAX)
        count = INT_MAX;
    if (neg)
        return -count;
    else
        return count;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << divide(a, b);
}
