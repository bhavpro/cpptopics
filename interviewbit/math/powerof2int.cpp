#include <bits/stdc++.h>

using namespace std;

int isPower(int A)
{
    if (A == 1)
        return 1;
    double nlog = log10(A);
    for (int i = 2; (long long)i * i <= A; i++)
    {
        double power = nlog / log10(i);
        if(power - ceil(power) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int a = 4;
    double power = log10(a)/log10(2);
    cout << power;
}