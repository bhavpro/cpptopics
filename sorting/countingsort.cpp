#include <iostream>
#include <string.h>

using namespace std;

int a[] = {67, 37, 86, 24, 87, 45, 62, 94, 32, 12};
int n = sizeof(a) / sizeof(int);

int main()
{
    int *arr = new int[100];

    memset(arr, 0, sizeof(int) * 100);
    for(int i = 0 ; i < 100;i++)
    {
        arr[a[i]]++;
    }

    int j = 0;
    for (int i = 0; i < 100; i++)
    {
        while (arr[i] > 0)
        {
            a[j++] = i;
            arr[i]--;
        }
    }
    delete[] arr;

    for (j = 0; j < n; j++)
    {
        cout << a[j] << " ";
    }
    return 0;
}