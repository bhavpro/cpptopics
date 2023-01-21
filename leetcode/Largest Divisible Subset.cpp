#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool func(int a, int b)
{
    if (a <= b)
        return true;
    return false;
}

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), func());
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back({1, i});
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[i] % nums[j] == 0 && (v[j].first + 1) >= v[i].first)
                    v[i] = {v[j].first + 1, j};
            }
        }

        int mi = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].first >= v[mi].first)
                mi = i;
        }
        int n = v[mi].first;
        vector<int> ans(n);
        cout << mi;
        while (n > 0)
        {
            ans[n - 1] = nums[mi];
            mi = v[mi].second;
            n--;
        }
        return ans;
    }
};