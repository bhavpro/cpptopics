#include <iostream>

using namespace std;

int totalwater(int *arr, int n)
{
    int *leftmax = new int[n], *rightmax = new int[n];
    leftmax[0] = arr[0];
    for (int i = 1; i < n; i++)
        leftmax[i] = max(leftmax[i - 1], arr[i - 1]);

    rightmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightmax[i] = max(rightmax[i + 1], arr[i + 1]);

    int store = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int lm = leftmax[i];
        int rm = rightmax[i];
        int th = min(lm, rm);
        if (th <= arr[i])
            continue;

        store += (th - arr[i]);
    }
    return store;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Total Water : " << totalwater(arr, n);
    return 0;
}