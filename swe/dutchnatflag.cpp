#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 5, 24, 21, 35, 14, 12, 4, 30};
    int n = sizeof(arr) / sizeof(int);

    int i = -1, j = -1;
    int t1 = 15, t2 = 30;
    for (int k = 0; k < n; k++)
    {
        if (arr[k] <= t1)
        {
            j++;
            i++;
            swap(arr[i], arr[j]);
            if (j != k)
                swap(arr[k], arr[i]);
        }
        else if (arr[k] >= t2)
        {
        }
        else
        {
            j++;
            swap(arr[k], arr[j]);
        }
    }

    for (int x : arr)
        cout << x << " ";

    return 0;
}