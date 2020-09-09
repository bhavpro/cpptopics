#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, int B)
{
    int i = 0;
    int cun0 = 0;
    int maxc = 0;
    for (int j = 0; j < A.size(); j++)
    {
        if (!A[j])
        {
            cun0++;
        }
        while (cun0 > B)
        {
            if (A[i] == 0)
                cun0--;
            i++;
        }
        if (maxc < (j - i + 1))
            maxc = j - i + 1;
    }
    return maxc;
}
