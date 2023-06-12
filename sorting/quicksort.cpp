#include <vector>
#include <iostream>
using namespace std;

class sortit
{
public:
    void swap(int &a, int &b)
    {
        if (a != b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
    }

    void partition(vector<int> &a, int l, int r, int m)
    {
        // take all elements to their correct parts
        for (int i = l, j = m + 1; i < m && j <= r;)
        {
            if (a[i] < a[m])
                i++;
            else if (a[j] > a[m])
                j++;
            else
            {
                swap(a[i], a[j]);
                i++;
                j++;
            }
        }
    }

    void qs(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;

        // take m element to its correct postition
        int count = 0;
        for (int i = l; i < r; i++)
            if (nums[i] < nums[r])
                count++;

        int pi = l + count;
        swap(nums[r], nums[pi]);
        partition(nums, l, r, l + count);

        // merge sort other parts
        qs(nums, l, pi - 1);
        qs(nums, pi + 1, r);
    }
};

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        if (nums.size() > 1)
        {
            sortit a;
            a.qs(nums, 0, nums.size() - 1);
        }
        return nums;
    }
};

int main()
{
    int n = 4;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Solution b;
    b.sortArray(a);
    for (int x : a)
        cout << x << " ";
}