#include <bits/stdc++.h>

using namespace std;

class tripe
{
public:
    int val, i, j;
};

vector<int> solve(int A, vector<int> &B)
{
    int n = B.size();
    vector<vector<tripe>> dp(n + 1, vector<tripe>(A + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= A; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = {0, -1, -1};
            else
            {
                dp[i][j] = {dp[i - 1][j].val, i - 1, j};
                if (j - B[i - 1] >= 0)
                {
                    tripe subt = dp[i][j - B[i - 1]];
                    if (subt.val > dp[i][j].val)
                    {
                    }
                    else if (subt.val == dp[i][j].val)
                    {
                    }
                }
            }
        }
    }
}
