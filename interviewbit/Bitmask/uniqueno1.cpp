#include <bits/stdc++.h>

using namespace std;

int singleNumber(const vector<int> &A)
{
    int xo = 0;
    for (int i = 0; i < A.size(); i++)
    {
        xo ^= A[i];
    }
    return xo;
}
