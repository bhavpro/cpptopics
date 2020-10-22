#include <bits/stdc++.h>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxc = 0;
    int cc = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] & 1)
        {
            cc++;
        }
        else
        {
            cc = 0;
        }
        maxc = max(cc, maxc);
    }
    return maxc;
}