#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int j = nums[i];
            for (int k = i + j; k > i; k--)
            {
                if (k >= n)
                    continue;
                if (dp[k] == -1)
                    dp[k] = dp[i] + 1;
                else
                    break;
            }
        }
        return dp[n - 1];
    }
};