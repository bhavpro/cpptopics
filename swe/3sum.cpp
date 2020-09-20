#include <bits/stdc++.h>

using namespace std;

#define sortit(x) sort(x.begin(), x.end())

namespace ch
{
    struct hash
    {
        size_t operator()(const vector<int> &v)const
        {
            return v[0] - v[1] + v[2];
        }
    };
}; // namespace ch

vector<vector<int>> threeSum(vector<int> &A)
{
    sortit(A);
    vector<vector<int>> ans;
    unordered_set<vector<int>, ch::hash> s;
    for (int i = 0; i < A.size() - 2; i++)
    {
        if (i > 0)
            if (A[i] == A[i - 1])
                continue;

        int j = i + 1;
        int k = A.size() - 1;
        while (j < k)
        {
            if (A[j] + A[k] < -A[i])
                j++;
            else if (A[j] + A[k] > -A[i])
                k--;
            else
            {
                s.insert({A[i], A[j], A[k]});
                j++;
            }
        }
    }
    for (auto v : s)
        ans.push_back(v);
    return ans;
}