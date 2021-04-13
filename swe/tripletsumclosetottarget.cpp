#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int arr[] = {1, 3, 56, 23, 69, -93, 47, 20, -30, -45, -24, 62, 75, 43, 64, 57};
    int n = sizeof(arr) / sizeof(int);

    sort(arr, arr + n);
    int t1, t2, t3;

    int d2 = INT_MAX;
    int target = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int t = target - arr[i];
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {

            int d1 = abs(arr[i] + arr[j] + arr[k] - target);
            if (d1 <= d2)
            {
                d2 = d1;
                t1 = arr[i];
                t2 = arr[j];
                t3 = arr[k];
            }

            if (arr[j] + arr[k] == t)
            {
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
                j++;
                continue;
            }
        }
    }
        cout << t1 << "*" <<t2 << " " << t3 << "\n"; 

    return 0;
}