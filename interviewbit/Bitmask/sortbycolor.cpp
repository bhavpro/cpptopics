#include <bits/stdc++.h>

using namespace std;

void sortColors(vector<int> &A)
{
    int i = -1;
    for (int j = 0; j < A.size(); j++)
    {
        if (A[j] == 0)
        {
            i++;
            if (i != j)
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    for (int j = i+1; j < A.size(); j++)
    {
        if (A[j] == 1)
        {
            i++;
            if (i != j)
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}
