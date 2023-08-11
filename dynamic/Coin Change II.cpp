#include <vector>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (j == 0)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = (i > 0 ? dp[i - 1][j] : 0);

                    if (j >= coins[i])
                        dp[i][j] += dp[i][j - coins[i]];
                }
            }
        }
        return dp[coins.size() - 1][amount];
    }
};