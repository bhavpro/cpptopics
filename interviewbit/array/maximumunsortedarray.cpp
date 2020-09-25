#include <bits/stdc++.h>

using namespace std;

vector<int> subUnsort(vector<int> &A)
{
    int l, r;
    vector<int> temp(A);
    int n = temp.size();
    sort(temp.begin(), temp.end());
    // set l
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            if (temp[i] == A[i])
                return {-1};
            if (temp[i] != A[i])
                return {temp[i]};
            continue;
        }
        if (A[i] != temp[i])
        {
            l = i;
            break;
        }
    }

    // set r
    for (int i = n - 1; i >= 0; i--)
    {
        if (temp[i] != A[i])
        {
            r = i;
            break;
        }
    }
    return {l, r};
}

vector<int> subUnsortop(vector<int> &A)
{
    int s, e;
    int n = A.size();
    // choose s
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            s = i;
            break;
        }
    }

    // choose e
    for (int i = n - 1; i > 0; i--)
    {
        if (A[i] < A[i - 1])
        {
            e = i;
            break;
        }
    }

    // max and min cumulative array

    vector<int> cmin(s + 1), cmax(n - e);
    for (int i = 0; i <= s; i++)
    {
    }
}