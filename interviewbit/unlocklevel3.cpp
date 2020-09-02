#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> prettyPrint(int A)
{
    int n = (A << 1) - 1;
    vector<vector<int>> ans(n, vector<int>(n));
    pair<int, int> a[4];
    for (int i = 0; i < 4; i++)
        a[i] = {n >> 1, n >> 1};

    for (int i = 1; i <= A; i++)
    {
        int r, c;
        // top row
        r = a[0].first;
        for (c = a[0].second; c <= a[1].second; c++)
            ans[r][c] = i;

        // bottom row
        r = a[3].first;
        for (c = a[3].second; c <= a[2].second; c++)
            ans[r][c] = i;

        // left col
        c = a[0].second;
        for (r = a[0].first; r <= a[3].first; r++)
            ans[r][c] = i;

        // right col
        c = a[1].second;
        for (r = a[1].first; r <= a[2].first; r++)
            ans[r][c] = i;

        // update row and column
        a[0] = {a[0].first - 1, a[0].second - 1};
        a[1] = {a[1].first - 1, a[1].second + 1};
        a[2] = {a[2].first + 1, a[2].second + 1};
        a[3] = {a[3].first + 1, a[3].second - 1};
    }
    return ans;
}
