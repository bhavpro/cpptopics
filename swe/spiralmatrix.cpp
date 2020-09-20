#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int dir = 0;
    int t = 0, b = matrix.size() - 1, l = 0, r = matrix[0].size() - 1;
    while (l <= r && t <= b)
    {
        if (dir == 0) // right
        {
            for (int i = l; i <= r; i++)
            {
                ans.push_back(matrix[t][i]);
            }
            t++;
        }
        else if (dir == 1) // down
        {
            for (int i = t; i <= b; i++)
            {
                ans.push_back(matrix[i][r]);
            }
            r--;
        }
        else if (dir == 2) // left
        {
            for (int i = r; i >= l; i--)
            {
                ans.push_back(matrix[b][i]);
            }
            b--;
        }
        else // dir = 4 up
        {
            for (int i = b; i >= t; i--)
            {
                ans.push_back(matrix[i][l]);
            }
            l++;
        }
        dir = (dir + 1) % 4;
    }
    return ans;
}