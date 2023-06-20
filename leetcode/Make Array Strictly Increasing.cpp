#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        sort(arr2.begin(), arr2.end());
        int count = 0;
        for (int i = 1; i < arr1.size() - 1; i++)
            if (arr1[i] >= arr1[i + 1] || arr1[i] <= arr1[i - 1])
            {
                vector<int>::iterator ptr = upper_bound(arr2.begin(), arr2.end(), arr1[i - 1]);
                if (ptr == arr2.end())
                    return -1;
                else
                {
                    arr1[i] = *ptr;
                    count++;
                }
            }

        // end is special
        if (arr1[n - 2] >= arr1[n - 1])
        {
            vector<int>::iterator ptr = upper_bound(arr2.begin(), arr2.end(), arr1[n - 2]);
            if (ptr == arr2.end())
                return -1;
            else
            {
                arr1[n - 1] = *ptr;
                count++;
            }
        }

        return count;
    }
};