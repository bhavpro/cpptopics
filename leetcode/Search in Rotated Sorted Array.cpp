#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target, int s = -1, int e = -1)
    {
        if (s == -1)
        {
            s = 0;
            e = nums.size() - 1;
            return search(nums, target, s, e);
        }

        int mid = (s + e) >> 1;
        if (target == nums[mid])
            return mid;

        if (s + 1 == e || s + 2 == e)
            if (target == nums[s])
                return s;
            else if (target == nums[e])
                return e;

        if (nums[mid + 1] <= nums[e] && target >= nums[mid + 1] && target <= nums[e])
            return search(nums, target, mid + 1, e);
        else if ((mid + 1 != e) && target >= nums[mid + 1] || target <= nums[e])
            return search(nums, target, mid + 1, e);

        if (nums[s] <= nums[mid - 1] && target >= nums[s] && target <= nums[mid - 1])
            return search(nums, target, s, mid - 1);
        else if ((mid - 1 != s) && target >= nums[s] || target <= nums[mid - 1])
            return search(nums, target, s, mid - 1);

        return -1;
    }
};