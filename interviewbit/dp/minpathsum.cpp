#include <bits/stdc++.h>

using namespace std;
/*
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
  
*/

int minimumTotal(vector<vector<int>> &A)
{
    if (A.size() == 0)
        return 0;
    vector<int> dp(A.size());
    dp[0] = A[0][0];
    int prev = 0;
    for (int i = 1; i < A.size(); i++)
    {
        int n = A[i].size();
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
            {
                prev = dp[0];
                dp[0] = dp[0] + A[i][0];
                continue;
            }
            if (j == n - 1)
            {
                dp[j] = prev + A[i][j];
                continue;
            }
            int temp = dp[j];
            dp[j] = min(prev, temp);
            dp[j] += A[i][j];
            prev = temp;
        }
    }
    int minel = dp[0];
    for (int i = 1; i < dp.size(); i++)
    {
        minel = min(minel, dp[i]);
    }
    return minel;
}

int minimumTotal(vector<vector<int>> &A)
{
    int n = A.size();
    vector<int> dp(n);
    dp[0] = A[0][0];
    int prev;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                prev = dp[0];
                dp[0] = prev + A[i][j];
            }
            else if (j == i)
            {
                dp[j] = prev + A[i][j];
            }
            else
            {
                int temp = dp[j];
                dp[j] = min(temp, prev) + A[i][j];
                prev = temp;
            }
        }
    }

    return *min_element(dp.begin(), dp.end());
}
