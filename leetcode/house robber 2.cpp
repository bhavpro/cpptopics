#include <vector>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        vector<int> sum(nums.size(), 0);
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
                sum[0] = nums[0];
            else if (i == 1)
                sum[1] = nums[1];
            else if ((i == n - 1) && ((i & 1) == 0))
            {
                if (i >= 3)
                    sum[i] = sum[i - 3] + nums[i];
                else
                    sum[i] = nums[i];
            }
            else
                sum[i] = sum[i - 2] + nums[i];
        }
        if (sum.size() <= 0)
            return 0;
        if (sum.size() == 1)
            return sum[0];
        return max(sum[n - 1], sum[n - 2]);
    }
};