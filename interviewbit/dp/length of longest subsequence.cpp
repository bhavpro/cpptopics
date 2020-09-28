#include <bits/stdc++.h>

using namespace std;

int longestSubsequenceLength(const vector<int> &A)
{
    int n = A.size();
    vector<int> incdp(n);
    vector<int> decdp(n);
    for (int i = 0; i < n; i++)
    {
        incdp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[j] < A[i])
                incdp[i] = max(incdp[i], incdp[j] + 1);
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        decdp[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[i])
                decdp[i] = max(decdp[i], decdp[j] + 1);
        }
    }

    int maxval = 0;
    for (int i = 0; i < n; i++)
        maxval = max(maxval, decdp[i] + incdp[i] - 1);

    return maxval;
}
