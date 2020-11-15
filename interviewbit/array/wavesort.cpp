#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

vector<int> wave(vector<int> &A)
{
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size() - 1; i++)
    {
        if (i & 1) // inc
        {
            if (A[i] > A[i + 1])
            {
                swap(A[i], A[i + 1]);
            }
        }
        else // dec
        {
            if (A[i] < A[i + 1])
            {
                swap(A[i], A[i + 1]);
            }
        }
    }
    return A;
}
