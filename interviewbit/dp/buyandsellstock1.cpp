#include <bits/stdc++.h>

using namespace std;

int maxProfit(const vector<int> &A)
{
    int minb = -1;
    int maxp = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (i == 0)
        {
            minb = A[0];
        }
        else
        {
            if (minb < A[i])
                maxp = max(maxp, A[i] - minb);
            else
                minb = min(minb, A[i]);
        }
    }
    return maxp;
}
