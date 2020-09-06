#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &A)
{
    int i = 0;
    int cur = A[0];
    for (int j = 1; j < A.size(); j++)
    {
        if (cur != A[j])
        {
            cur = A[j];
            i++;
            if (i != j)
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    return i + 1;
}
