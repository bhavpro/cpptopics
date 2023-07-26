#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 1);
        int pre = 1, post = 1;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
            {
                // begin
                ans[i] *= pre;

                // end
                ans[n - 1 - i] *= post;
            }

            pre *= nums[i];
            post *= nums[n - 1 - i];
        }
        return ans;
    }
};