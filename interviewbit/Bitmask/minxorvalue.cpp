#include <bits/stdc++.h>

using namespace std;

int findMinXor(vector<int> &A)
{
    int minxor = A[0] ^ A[1];
    for (int j = 0; j < A.size(); j++)
    {
        for (int i = j + 1; i < A.size(); i++)
        {
            minxor = min(minxor, A[j] ^ A[i]);
        }
    }
    return minxor;
}

int bs(vector<int> &A, int s, int e, int bpos)
{
    int mask = 1 << bpos;
    int is = s, ie = e;
    while (s < e)
    {
        int mid = s + e;
        mid >>= 1;
        if (A[mid] & mask) // 1 occur
        {
            if (mid > s && !(A[mid - 1] & mask))
            {
                return mid - 1;
            }
            e = mid - 1;
        }
        else // 0 occur
        {
            if (mid < e && (A[mid + 1] & mask))
            {
                return mid;
            }
            s = mid + 1;
        }
    }
    if (ie == e)
        return e;
    else
        return s;
}

int rec(vector<int> &A, int s, int e, int bpos)
{
    int n = e - s + 1;
    // base
    if (s > e || n < 2)
        return -1;

    if (n == 2)
    {
        return (A[s] ^ A[e]);
    }

    // rec
    int pos0 = bs(A, s, e, bpos);
    int a0 = rec(A, s, pos0, bpos - 1);
    int a1 = rec(A, pos0 + 1, e, bpos - 1);

    if (a0 == -1)
        return a1;
    if (a1 == -1)
        return a0;
    return min(a0, a1);
}

int findMinXorop(vector<int> &A)
{
    sort(A.begin(), A.end());
    int minxor = rec(A, 0, A.size() - 1, (sizeof(int) << 3) - 1);
    return minxor;
}

int finalop(vector<int> &A)
{
    sort(A.begin(), A.end());
    int minxor = INT_MAX;
    for (int i = 1; i < A.size(); i++)
    {
        minxor = min(minxor, A[i] ^ A[i - 1]);
    }
    return minxor;
}