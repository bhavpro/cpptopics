#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int ct = 0;
        vector<int> subs;
        for (int x : nums)
        {
            if (x == 1)
                ct++;
            else
            {
                subs.push_back(ct);
                ct = 0;
            }
        }
        if (ct > 0)
            subs.push_back(ct);

        int prev = 0;
        int maxsum = 0;
        for (int x : subs)
        {
            cout << x << " ";
            if (x + prev > maxsum)
                maxsum = x + prev;
            prev = x;
        }
        return maxsum == nums.size() ? maxsum - 1 : maxsum;
    }
};