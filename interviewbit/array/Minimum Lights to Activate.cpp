#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, int B)
{
    int j = -1;
    int n = A.size();
    int count = 0;
    bool solved = true;

    bool foundabulb = true;

    // set the first light
    foundabulb = false;
    for (int i = B - 1; i >= 0; i--)
    {
        if (A[i] == 1)
        {
            foundabulb = 1;
            j = i;
            count++;
            break;
        }
    }
    if (!foundabulb)
        return -1;

    // set other lights
    for (int i = j + 1; i < n; i++)
    {
        j = i + ((B - 1) << 1);
        j = min(n - 1, j);
        if (i >= (n - 1 - (B - 1)))
            break;

        solved = false;
        for (; j >= i; j--)
        {
            if (A[j])
            {
                count++;
                solved = true;
                break;
            }
        }
        if (!solved)
            return -1;
        i = j;
    }
    
    return count;
}