#include <bits/stdc++.h>

using namespace std;

int cntBits(vector<int> &A)
{
    int mod = 1e9 + 7;
    long long count = 0;
    int n = sizeof(int) * 8;

    for (int j = 0; j < n; j++)
    {
        int mask = (1 << j);
        int c0 = 0, c1 = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] & mask)
                c1++;
            else
                c0++;
        }
        count = (count + c1 * c0) % mod;
    }
    return (count << 1) % mod;
}
