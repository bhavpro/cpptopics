#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        vector<int> sqarr;
        int tosq = 1;
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            int sq = tosq * tosq;
            if (sq == i)
            {
                sqarr.push_back(sq);
                tosq++;
                dp.at(i) = 1;
                continue;
            }
            for (int x : sqarr)
                dp.at(i) = min(dp.at(i), 1 + dp.at(i - x));
        }
        return dp.at(n);
    }
};