#include <bits/stdc++.h>

using namespace std;

int bulbs(vector<int> &A)
{
    int cnt = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
        {
            if (cnt & 1)
            {
                continue;
            }
            else
            {
                cnt++;
            }
        }
        else
        {
            if (cnt & 1)
            {
                cnt++;
            }
            else
            {
                continue;
            }
        }
    }
    return cnt;
}