#include <bits/stdc++.h>

using namespace std;

int inv(int *arr, int s, int e)
{
    // base
    if (s == e)
    {
        return 0;
    }
    if (s + 1 == e)
    {
        if (arr[s] > arr[e])
        {
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            return 1;
        }
        return 0;
    }

    // rec
    int mid = s + e;
    mid /= 2;
    int sum = inv(arr, s, mid) + inv(arr, mid + 1, e);
    int i = s, j = mid + 1;
    vector<int> temp(e - s + 1);
    int k = 0;
    while (i != mid + 1 && j != e + 1)
    {
        if (arr[i] > arr[j])
        {
            sum += mid - i + 1;
            temp[k++] = arr[j++];
            continue;
        }
        temp[k++] = arr[i++];
    }
    while (i != mid + 1)
    {
        temp[k++] = arr[i++];
    }
    while (j != e + 1)
    {
        temp[k++] = arr[j++];
    }
    for (i = 0; i < e - s + 1; i++)
    {
        arr[s + i] = temp[i];
    }
    return sum;
}

int main()
{
    int arr[] = {1, 5, 2, 6, 3, 0};
    int n = 6;
    cout << inv(arr, 0, n - 1);
    return 0;
}