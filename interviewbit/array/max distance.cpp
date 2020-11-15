#include <bits/stdc++.h>

using namespace std;

int maximumGap(const vector<int> &A)
{
    int diff = 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[i] <= A[j])
            {
                diff = max(j - i, diff);
            }
        }
    }
    return diff;
}

int maximumGap(const vector<int> &A)
{
    int n = A.size();
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = {A[i], i};
    sort(arr.begin(), arr.end());

    int minval = INT_MAX;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].second < minval)
            minval = arr[i].second;

        ans = max(ans, arr[i].second - minval);
    }
    return ans;
}
