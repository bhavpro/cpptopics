#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long ms = 0;
        int ct = 0;
        int mindiff = 1e9 + 7;
        int negdiff = -1e9 - 7;
        for (const int &x : nums)
        {
            int mod = x ^ k;
            if (mod > x)
            {
                ms += mod;
                ct++;
                mindiff = min(mindiff, mod - x);
            }
            else
            {
                negdiff = max(negdiff, mod - x);
                ms += x;
            }
        }
        return ct & 1 ? ms - (-negdiff < mindiff ? -negdiff : mindiff) : ms;
    }
};

int main()
{
    vector<int> nums = {24, 78, 1, 97, 44};
    int k = 6;
    vector<vector<int>> edges = {{0, 2}, {1, 2}, {4, 2}, {3, 4}};
    Solution s;
    cout << s.maximumValueSum(nums, k, edges);
    return 0;
}