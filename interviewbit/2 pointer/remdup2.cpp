#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b)
{
    if (a == b)
        return;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int removeDuplicates(vector<int> &A)
{
    int i = 0;
    int count = 1;
    for (int j = 1; j < A.size(); j++)
    {
        if (A[j] > A[i])
        {
            count = 0;
            // swap i,j if not same
            i++;
            if (i != j)
            {
                swap(A[i], A[j]);
            }
        }
        else if (A[j] == A[i] && count == 1)
        {
            // swap i,j
            swap(A[++i], A[j]);
        }
        count++;
    }
    return i + 1;
}
