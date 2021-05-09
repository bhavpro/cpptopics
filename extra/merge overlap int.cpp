#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct interval
{
    int s, e;
};

bool sorter(interval a, interval b)
{
    bool ans = false;
    ans = (a.s <= b.s);
    if (a.s == b.s)
        ans = (a.e <= b.e);
    return ans;
}

vector<interval> mergeint(interval *arr, int n)
{
    sort(arr, arr + n, sorter);
    vector<interval> temps;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].e >= arr[i + 1].s && i < n - 1)
        {
            arr[i + 1].s = arr[i].s;
            arr[i + 1].e = max(arr[i].e, arr[i + 1].e);
        }
        else
        {
            temps.push_back(arr[i]);
        }
    }
    return temps;
}

int main()
{
    interval arr[] = {{1, 4}, {3, 5}, {6, 7}, {7, 9}, {10, 12}, {7, 8}};
    int n = sizeof(arr) / sizeof(interval);

    vector<interval> ans = mergeint(arr, n);
    int nans = ans.size();
    for (int i = 0; i < nans; i++)
    {
        cout << ans[i].s << " " << ans[i].e << "\n";
    }

    return 0;
}