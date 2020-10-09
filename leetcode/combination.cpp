#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
        ans.push_back(vector<int>({i}));

    for (int i = 2; i <= k; i++)
    {
        vector<vector<int>> prev(ans);
        ans.clear();
        for (int j = 0; j < prev.size(); j++)
        {
            int pval = prev[j][i - 2];
            for (int l = pval + 1; l <= n; l++)
            {
                vector<int> arr = prev[j];
                arr.push_back(l);
                ans.push_back(arr);
            }
        }
    }
    return ans;
}