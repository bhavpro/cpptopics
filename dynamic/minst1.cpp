#include <iostream>
#include <cstring>
using namespace std;

// n-1 , n/2 , n/3

int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    memset(arr, 0, sizeof(int) * (n + 1));
    arr[0] = -1;
    arr[1] = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i + 1] == 0)
            arr[i + 1] = arr[i] + 1;
        if ((i << 1) <= n && arr[i << 1] == 0)
            arr[i << 1] = arr[i] + 1;
        if ((i * 3) <= n && arr[i * 3] == 0)
            arr[i * 3] = arr[i] + 1;
    }

    cout << arr[n];
    return 0;
}