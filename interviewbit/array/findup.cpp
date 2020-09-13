#include <bits/stdc++.h>

using namespace std;

int repeatedNumber(const vector<int> &A)
{
    bitset<100005> b;
    b.reset();
    for (int i = 0; i < A.size(); i++)
    {
        if (b[A[i]])
            return A[i];
        b[A[i]] = 1;
    }
    return -1;
}
