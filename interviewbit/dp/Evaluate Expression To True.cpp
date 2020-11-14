#include <bits/stdc++.h>

using namespace std;

bool ctob(char a)
{
    return (a == 'T' ? true : false);
}

bool operate(bool a, char o, bool b)
{
    if (o == '|')
        return a | b;
    if (o == '&')
        return a & b;
    return a ^ b;
}

int cnttrue(string A)
{
    int N = A.size();
    int n = (N >> 1) + 1;

    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int k = 0; k < n; k++)
    {
        for (int i = 0, j = k; i < n - k; i++)
        {
            if (i == j)
                dp[i][j] = ctob(A[i << 1]);
            else
            {
                for (int m = i; m < j; m++)
                {
                    dp[i][j] = operate(dp[i][k], A[(m << 1) + 1], dp[k][j]);
                    if (dp[i][j])
                        break;
                }
            }
        }
    }
}
