#include <bits/stdc++.h>

using namespace std;

int firstMissingPositive(vector<int> &A)
{
    // seperate out negtives and positives
    int n = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > 0)
        {
            n++;
            int temp = A[i];
            A[i] = A[n];
            A[n] = A[i];
        }
    }
    n++;
    if (n == A.size())
    {
        A.push_back(1);
        n++;
    }
    // n is the size of array for positives
    for (int i = 0; i < n; i++)
    {
        int ind = abs(A[i]);
        if (ind < n && A[ind] > 0)
            A[ind] = -A[ind];
    }

    // traverse
    for (int i = 1; i < n; i++)
    {
        if (A[i] > 0)
            return i;
    }
    return n + 1;
}
