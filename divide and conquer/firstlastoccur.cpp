#include <bits/stdc++.h>

using namespace std;

int fo(vector<int> arr, int ele)
{
    int s = 0;
    int e = arr.size() - 1;
    int f = -1;
    while (s <= e)
    {
        int mid = s + e;
        mid /= 2;
        if (arr[mid] == ele)
        {
            f = mid;
        }
        if (ele <= arr[mid])
        {
            e = mid - 1;
            continue;
        }
        s = mid + 1;
    }
    return f;
}

int lo(vector<int> arr, int ele)
{
    int e = arr.size() - 1;
    int s = 0;
    int f = -1;
    while (s < e)
    {
        int mid = s + e;
        mid /= 2;
        if (arr[mid] == ele)
        {
            f = mid;
        }
        if (ele >= arr[mid])
        {
            s = mid + 1;
            continue;
        }
        e = mid - 1;
    }
    return f;
}

int main()
{
    vector<int> arr(40);
    arr = {1, 2, 3, 4, 4, 4, 5, 6};
    cout << fo(arr, 4) << "\n";
    cout << lo(arr, 4);
    return 0;
}