#include <bits/stdc++.h>

using namespace std;

int search(int *a, int n, int key)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        // mid lies in  part 1
        if (a[s] <= a[mid])
        {
            if (a[mid] == key)
            {
                return mid;
            }
            if (key > a[s] && key < a[mid])
            {
                e = mid - 1;
                continue;
            }
            s = mid + 1;
            continue;
        }

        // mid lies in part 2
        if (a[mid] < a[e])
        {
            if (a[mid] == key)
            {
                return mid;
            }
            if (key > a[mid] && key < a[e])
            {
                s = mid + 1;
                continue;
            }
            e = mid - 1;
            continue;
        }
    }
    return -1;
}

int main()
{
    int a[] = {4, 5, 1, 2, 3};
    int n = 5;
    int key = 2;
    return 0;
}