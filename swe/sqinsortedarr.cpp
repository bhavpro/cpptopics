#include <iostream>

using namespace std;

int *csa(int *arr, int n)
{
    int i = 0;
    while (arr[i] < 0 && i < n)
        i++;

    i--;
    int j = i + 1;

    int *na = new int[n];
    int k = 0;
    while (i >= 0 && j < n)
    {
        if (-arr[i] <= arr[j])
        {
            na[k] = arr[i] * arr[i];
            k++;
            i--;
        }
        else
        {
            na[k] = arr[j] * arr[j];
            j++;
            k++;
        }
    }

    while (i >= 0)
    {
        na[k] = arr[i] * arr[i];
        k++;
        i--;
    }

    while (j < n)
    {
        na[k] = arr[j] * arr[j];
        j++;
        k++;
    }

    return na;
}

int main()
{
    int arr[] = {-2, -1, 0, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    int *ne = csa(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << ne[i] << " ";
    }
    delete[] ne;

    return 0;
}