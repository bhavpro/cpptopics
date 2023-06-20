#include <vector>
using namespace std;

int findmax(vector<int> a)
{
    int mv = 0;
    for (int i = 0; i < a.size(); i++)
        mv = max(mv, a[i]);
    return mv;
}

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> ct(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++)

            if (i == 0)
                ct[0] = 1;
            else
                for (int j = 0; j < i; j++)
                    if (nums[j] < nums[i])
                        ct[i] = max(ct[i], ct[j] + 1);

        return findmax(ct);
    }
};