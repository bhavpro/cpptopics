#include <bits/stdc++.h>

using namespace std;

int maxArr(vector<int> &A)
{
    int minne = INT_MAX;
    int minpo = INT_MAX;
    int maxne = INT_MIN;
    int maxpo = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        minne = min(A[i] - i, minne);
        minpo = min(A[i] + i, minpo);
        maxpo = max(A[i] + i, maxpo);
        maxne = max(A[i] - i, maxne);
    }
    

    return max(maxne - minne, maxpo - minpo);
}