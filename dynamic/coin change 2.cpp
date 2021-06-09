#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j == 0 || i == 0)
                {
                    if (j == 0)
                        dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp[n][amount];
    }
};