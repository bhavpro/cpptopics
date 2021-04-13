#include <iostream>

using namespace std;

int remd(int *arr, int n)
{
    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    return j + 1;
}

int main()
{
    int arr[] = {2, 3, 3, 3, 6, 9, 9};
    int n = sizeof(arr) / sizeof(int);

    n = remd(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}