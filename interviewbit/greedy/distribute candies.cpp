#include <bits/stdc++.h>

using namespace std;

int candy(vector<int> &A)
{
    int n = A.size();
    int j = -1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
        }
        else
        {
            if (A[i] > A[i + 1])
            {
                j = (j == -1 ? i : j);
            }
            else
            {
                int s = i - j + 1;
                count += s * (s + 1) / 2;
                
            }
        }
    }
}
