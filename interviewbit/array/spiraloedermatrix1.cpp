#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(const vector<vector<int>> &A)
{
    vector<int> ans;
    int t = 0;
    int b = A.size() - 1;
    int l = 0;
    int r = A[0].size() - 1;
    int dir = 0;
    while (t <= b && l <= r)
    {
        if (dir == 0)
        {
            for (int i = l; i <= r; i++)
            {
                ans.push_back(A[t][i]);
            }
            t++;
            dir++;
            continue;
        }
        if (dir == 1)
        {
            for (int i = t; i <= b; i++)
            {
                ans.push_back(A[i][r]);
            }
            r--;
            dir++;
            continue;
        }
        if (dir == 2)
        {
            for (int i = r; i >= l; i--)
            {
                ans.push_back(A[b][i]);
            }
            b--;
            dir++;
            continue;
        }
        for (int i = b; i >= t; i--)
        {
            ans.push_back(A[i][l]);
        }
        l++;
        dir = 0;
        continue;
    }
    return ans;
}
