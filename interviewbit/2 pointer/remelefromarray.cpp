#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int> &A, int B)
{
    int i = -1;
    for (int j = 0; j < A.size(); j++)
    {
        if (A[j] != B)
        {
            i++;
            A[i] = A[j];
        }
    }
    return i + 1;
}
