#include <bits/stdc++.h>

using namespace std;

int hammingDistance(const vector<int> &A)
{
    int mod = 1e9 + 7;
    long long hd = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[i] != A[j])
            {
                int temp = A[i] ^ A[j];
                hd += __builtin_popcount(temp);
                hd %= mod;
            }
        }
    }
    hd = (hd << 1) % mod;
    return hd;
}

int hammingDistanceop(const vector<int> &A)
{
    int n = sizeof(int) * 8;
    int mod = 1e9 + 7;
    long long hd = 0;
    for (int i = 0; i < n; i++)
    {
        int c1 = 0, c0 = 0;
        for (int j = 0; j < A.size(); j++)
        {
            int x = A[j];
            int mask = (1 << i);
            if (x & mask)
                c1++;
            else
                c0++;
        }
        hd = (hd + (c1 * c0)) % mod;
    }
    hd = (hd << 1) % mod;
    return hd;
}
int hammingDistance(const vector<int> &A)
{
    int inputSize = A.size();
    int mod = 1000000007;
    int sum = 0;
    for (int bitPosition = 0; bitPosition < 31; bitPosition++)
    {
        int cntBitOne = 0, cntBitZero = 0;
        for (int i = 0; i < inputSize; i++)
        {
            if (A[i] & (1 << bitPosition))
                cntBitOne++;
            else
                cntBitZero++;
        }
        sum = sum + ((2LL * cntBitOne * cntBitZero) % mod);
        if (sum >= mod)
            sum = sum - mod;
    }
    return sum;
}