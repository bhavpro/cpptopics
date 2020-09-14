#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A)
{
    int i = -1, j = -1, k = -1;
    int n = A.size() - 1;
    // let set i , j , k
    bool allset = false;
    for (i = 0; i < n - 2; i++)
    {
        for (j = i + 1; j < n - 1; j++)
        {
            for (k = j + 1; k < n; k++)
            {
                if (A[i] < A[j] && A[j] < A[k])
                {
                    allset = true;
                    break;
                }
            }
            if (allset)
            {
                break;
            }
        }
        if (allset)
        {
            break;
        }
    }

    if (allset == false)
        return 0;
    // we set i , j ,k
    // now make it max
    int itr = k + 1;
    while (itr < n)
    {
        if (A[itr] > A[k])
        {
            i = j;
            j = k;
            k = itr;
        }
        itr++;
    }
    return A[i] + A[j] + A[k];
}
