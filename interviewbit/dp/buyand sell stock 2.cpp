#include <bits/stdc++.h>

using namespace std;

int maxProfit(const vector<int> &A)
{
    int b = -1;
    int totalp = 0;
    int curp = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (i == 0 || A[i] < A[i - 1])
        {
            b = A[i];
            totalp += curp;
            curp = 0;
        }
        else
        {
            curp = max(curp, A[i] - b);
        }
    }
    totalp += curp;
    return totalp;
}
