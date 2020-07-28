#include <iostream>

using namespace std;

int arr[] = {2, 7, 8, 6, 1, 5, 4};
int n = 7;

int part(int *arr, int s, int e)
{
    int i = s - 1;
    int j = s;
    int p = arr[e];
    for (j = s; j <= e; j++)
    {
        if (arr[j] <= p)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    return i;
}

void quick(int *arr, int s, int e)
{
    cout << s << " " << e << "\n"
         << flush;
    // base
    if (s >= e)
    {
        return;
    }

    // rec
    int p = part(arr, s, e);
    quick(arr, s, p - 1);
    quick(arr, p + 1, e);
}

int main()
{
    quick(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}