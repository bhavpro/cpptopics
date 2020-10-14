#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generateMatrix(int A)
{
    int n = A * A;
    vector<vector<int>> spom(A, vector<int>(A));
    int t = 0, b = A - 1, l = 0, r = A - 1;
    int dir = 0;
    for (int i = 1; i <= n;)
    {
        if (dir == 0)
        {
            for (int j = l; j <= r; j++)
            {
                spom[t][j] = i++;
            }
            t++;
        }
        else if (dir == 1)
        {
            for (int j = t; j <= b; j++)
            {
                spom[j][r] = i++;
            }
            r--;
        }
        else if (dir == 2)
        {
            for (int j = r; j >= l; j--)
            {
                spom[b][j] = i++;
            }
            b--;
        }
        else if (dir == 3)
        {
            for (int j = b; j >= t; j--)
            {
                spom[j][l] = i++;
            }
            l++;
        }
        dir = (dir + 1) % 4;
    }
    return spom;
}
