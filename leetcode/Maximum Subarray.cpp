#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> cs(n), ms(n);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                cs[0] = max(nums[0], 0);
                ms[0] = cs[0];
                continue;
            }
            cs[i] = max(cs[i - 1] + nums[i], 0);
            ms[i] = max(cs[i], ms[i - 1]);
        }
        if (ms[n - 1] <= 0)
        {
            int minval = -1e9;
            for (int i = 0; i < n; i++)
                minval = max(minval, nums[i]);
            return minval;
        }
        return ms[n - 1];
    }
};