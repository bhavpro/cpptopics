#include <bits/stdc++.h>

using namespace std;

int solve2p(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int i = 0, j = 1;

    while (i < A.size() && j < A.size())
    {
        int diff = A[j] - A[i];
        if (diff == B && i != j)
            return 1;
        if (diff > B)
            i++;
        else
            j++;
    }
    return 0;
}

int solveop(vector<int> &A, int B)
{
    unordered_map<int, bool> exist;

    for (int i = 0; i < A.size(); i++)
    {
        if (exist[A[i]] && B == 0)
            return 1;
        exist[B + A[i]] = true;
    }
    if (B == 0)
        return 0;
    for (int i = 0; i < A.size(); i++)
        if (exist[A[i]])
            return 1;

    return 0;
}
