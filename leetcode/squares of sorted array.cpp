#include <bits/stdc++.h>

using namespace std;

vector<int> sortedSquares(vector<int> &A)
{
    vector<int> ans;
    for (int i = 0; i < A.size(); i++)
    {
        ans.push_back(A[i] * A[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

vector<int> sortedSquares(vector<int> &A)
{
    int n = A.size();
    vector<int> ans;
    int i = 0, j = 0;
    j = lower_bound(A.begin(), A.end(), 0) - A.begin();
    i = j - 1;
    while (i >= 0 && j < n)
    {
        if (abs(A[i]) < A[j])
            ans.push_back(A[i] * A[i--]);
        else
            ans.push_back(A[j] * A[j++]);
    }

    while (i >= 0)
        ans.push_back(A[i] * A[i--]);

    while (j < n)
        ans.push_back(A[j] * A[j++]);

    return ans;
}