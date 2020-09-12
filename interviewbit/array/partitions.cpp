#include <bits/stdc++.h>

using namespace std;

int solve(int A, vector<int> &B)
{
    int count = 0;
    long long totalsum, sumeach = 0;
    for (int i = 0; i < A; i++)
        totalsum += B[i];
    if (totalsum % 3)
        return count;
    sumeach = totalsum / 3;
    int sumi = 0;
    for (int i = 0; i < A - 2; i++)
    {
        sumi += B[i];
        if (sumi == sumeach)
        {
            int sumj = 0;
            for (int j = i + 1; j < A - 1; j++)
            {
                sumj += B[j];
                if (sumj == sumeach)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

#define ll long long

int solve1(int A, vector<int> &B)
{
    ll totalsum = 0;
    for (int val : B)
    {
        totalsum += (ll)(val);
    }

    if (totalsum % 3 != 0)
        return 0;

    int sumeach = totalsum / 3;
    ll cur = 0, x = 0, ans = 0;
    for (int i = 0; i < A - 1; ++i)
    {
        cur += B[i];
        if (cur == 2 * sumeach)
            ans += x;
        if (sumeach == cur)
            x++;
    }
    return ans;
}