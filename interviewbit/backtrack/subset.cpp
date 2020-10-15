#include <bits/stdc++.h>

using namespace std;

void rec(vector<int> &A, vector<int> prev, vector<vector<int>> &ans, int ind = 0)
{
    ans.push_back(prev);
    prev.push_back(-1);
    for (int i = ind; i < A.size(); i++)
    {
        prev[prev.size() - 1] = A[i];
        rec(A, prev, ans, i + 1);
    }
}

vector<vector<int>> subsets(vector<int> &A)
{
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    rec(A, vector<int>(), ans);
    return ans;
}
