#include <bits/stdc++.h>

using namespace std;

void rec(int n, int k, int num, vector<vector<int>> &ans, int i, vector<int> &temp)
{
    // base
    if (i == k)
    {
        ans.push_back(temp);
        return;
    }
    if (num == n + 1)
    {
        return;
    }

    // rec
    temp[i] = num;
    rec(n, k, num + 1, ans, i + 1, temp);
    rec(n, k, num + 1, ans, i, temp);
}

vector<vector<int>> combine(int A, int B)
{
    vector<vector<int>> ans;
    vector<int> temp(B);
    rec(A, B, 1, ans, 0, temp);
    return ans;
}
