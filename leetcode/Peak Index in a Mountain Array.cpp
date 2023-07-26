#include <vector>
using namespace std;

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int s = 0, e = arr.size();
        while (s < e)
        {
            int i = (s + e) >> 1;
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                return i;
            else if (arr[i] > arr[i - 1] && arr[i] < arr[i + 1])
                s = i;
            else
                e = i;
        }
        return -1;
    }
};