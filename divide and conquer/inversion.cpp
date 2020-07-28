#include <bits/stdc++.h>

using namespace std;

int arr[] = {1, 5, 2, 6, 3, 0};
int n = 6;

int invc(int arr[], int s, int e)
{
    // base
    if( s >= e)
    {
        return 0;
    }

    // rec
    int mid = s + e;
    mid /= 2;
    int sum = invc(arr, s, mid) + invc(arr, mid + 1, e);

    // sort array arr
    vector<int> a(n);
    int i = s, j = mid + 1;
    int k = s;
    int cross = 0;
    while (i != (mid + 1) && (j != e + 1))
    {
        if (arr[i] < arr[j])
        {
            a[k++] = arr[i++];
            continue;
        }
        cross += (mid + 1 - i);
        a[k++] = arr[j++];
    }

    while (i != mid + 1)
    {

        a[k++] = arr[i++];
    }

    while (j != e + 1)
    {
        a[k++] = arr[j++];
    }

    for(int i =s;i <=e;i++)
    {
        arr[i] = a[i];
    }

    return cross + sum;
}

int main()
{
    cout << invc(arr, 0, n - 1);
    return 0;
}