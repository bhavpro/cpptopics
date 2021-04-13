/*

1 3 7 4 - 3 8 - 5 4 10 9 6 11 10 20

    2 -1
     4 11

    - 3 11
    */

#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 13,3, 7, 4, -3, 8, -5, 4, 10, 9, 6, 11, 10, 20};
    int n = sizeof(arr) / sizeof(int);

    int s = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            s = i;
            break;
        }
    }

    if (s == n - 1)
    {
        cout << "Array Sorted";
        return 0;
    }

    int e = 0;
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] < arr[i - 1])
        {
            e = i;
            break;
        }
    }

    // expand our window
    int mini = arr[s], maxi = arr[e];
    for (int i = s; i <= e; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(arr[i], maxi);
    }

    for (int i = 0; i < s; i++)
    {
        if (arr[i] > mini)
        {
            s = i;
            break;
        }
    }

    for (int i = n - 1; i > e; i--)
    {
        if (arr[i] < maxi)
        {
            e = i;
            break;
        }
    }

    cout << s << " " << e;
    return 0;
}