#include <bits/stdc++.h>

using namespace std;

int lbs(vector<int> a)
{
    int n = a.size();
    vector<int> lis(n), lds(n);
    lis[0] = 1;
    lds[n - 1] = 1;
    for (int i = 1; i < a.size(); i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    for (int i = a.size() - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < i; j++)
        {
            if (a[j] < a[i])
                lds[i] = max(lds[i], lds[j] + 1);
        }
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, lis[i] + lds[i] - 1);
    }
    return maxi;
}