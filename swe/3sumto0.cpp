#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1, 3, 56, 23, 69, -93, 47, 20, -30, -45, -24, 62, 75, 43, 64, 57};
    int n = sizeof(arr) / sizeof(int);

    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++)
    {
        int t = -arr[i];
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            if (arr[j] + arr[k] == t)
            {
                cout << arr[i] << " " << arr[j] << " " << arr[k] << "\n";
                j++;
                continue;
            }
            if (arr[j] + arr[k] > t)
            {
                k--;
                continue;
            }
            if (arr[j] + arr[k] < t)
            {
                j++ ;
                continue;
            }
        }
    }

    return 0;
}