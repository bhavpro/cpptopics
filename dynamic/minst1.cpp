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

    for (int i = 2; i <= n; i++)
    {
        int a = i % 2 == 0 ? arr[i >> 1] : 1e9;
        int b = i % 3 == 0 ? arr[i / 3] : 1e9;
        arr[i] = min(min(a, b), arr[i - 1]) + 1;
    }

    cout << arr[n];
    return 0;
}