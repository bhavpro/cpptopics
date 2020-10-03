#include <bits/stdc++.h>

using namespace std;

int lis(const vector<int> &A)
{
    int n = A.size();
    vector<int> dp(n);
    dp[0] = 1;
    int tmax = 1;
    for (int i = 1; i < n; i++)
    {
        int maxval = 0;
        int j = i - 1;
        while (j >= 0)
        {
            if (A[i] > A[j])
                maxval = max(maxval, dp[j]);
            j--;
        }
        tmax = max(dp[i] = maxval + 1, tmax);
    }
    return tmax;
}
