#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        vector<unordered_map<long long, int>> ans(nums.size());
        int ct = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                long long diff = (long long)nums[i] - nums[j];
                pair<long long, int> p = {diff, 2};
                ans[i][diff]
                for (int k = 0; k < ans[j].size(); k++)
                {
                    p = ans[j][k];
                    if (p.first == diff)
                    {
                        p.second++;
                        if (p.second >= 3)
                            ct++;
                        ans[i].push_back(p);
                    }
                }
            }
        }
        return ct;
    }
};