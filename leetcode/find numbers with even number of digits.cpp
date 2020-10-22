#include <bits/stdc++.h>

using namespace std;

int findNumbers(vector<int> &nums)
{
    int total = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int nod = log10(nums[i]);
        total += nod & 1 ? 1 : 0;
    }
    return total;
}