#include <bits/stdc++.h>

using namespace std;

void gen(vector<int> &A, int B, vector<int> prev, set<vector<int>> &ans, int i = 0)
{
    // base
    if (B == 0 && i == A.size())
    {
        ans.insert(prev);
        return;
    }

    if (B < 0 || i == A.size())
        return;

    // rec
    if (B - A[i] >= 0)
    {
        prev.push_back(A[i]);
        gen(A, B - A[i], prev, ans, i);
        gen(A, B - A[i], prev, ans, i + 1);
        prev.pop_back();
    }
    gen(A, B, prev, ans, i + 1);
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    set<vector<int>> ans;
    gen(A, B, vector<int>(), ans);
    vector<vector<int>> an;
    for (vector<int> x : ans)
        an.push_back(x);
    return an;
}
