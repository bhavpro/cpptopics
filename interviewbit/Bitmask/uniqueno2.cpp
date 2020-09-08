#include <bits/stdc++.h>

using namespace std;

int singleNumber(const vector<int> &A)
{
    int bits[32];
    memset(bits, 0, sizeof(bits));
    for (int i = 0; i < 32; i++)
    {
        int mask = (1 << i);
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] & mask)
            {
                bits[j]++;
            }
        }
    }
    int num = 0;
    for (int i = 31; i >= 0; i--)
    {
        num <<= 1;
        num += (bits[i] % 3);
    }
    return num;
}
