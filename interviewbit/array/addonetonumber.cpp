#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &A)
{
    int count = 0;
    for (int i = A.size() - 1; i >= 1; i--)
    {
        if (A[i] == 0)
            count++;
        else
            break;
    }
    A.erase(A.begin(),A.begin()+count);
    int c = 1;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        A[i] += c;
        c = A[i] / 10;
        A[i] = A[i] % 10;
        if (c == 0)
            break;
    }
    if (c == 1)
    {
        A.push_back(0);
        for (int i = A.size() - 1; i >= 1; i--)
        {
            A[i] = A[i - 1];
        }
        A[0] = 1;
    }
    return A;
}