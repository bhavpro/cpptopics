#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &A)
{
    vector<pair<int, bool>> v;
    for (int i = 0; i < A.size(); i++)
    {
        v.push_back({A[i][0], 1});
        v.push_back({A[i][1], 0});
    }

    sort(v.begin(), v.end());
    int maxval = 0;
    int currooms = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == 1)
            currooms++;
        else
            currooms--;
        maxval = max(maxval,currooms);
    }
    return maxval;
}
