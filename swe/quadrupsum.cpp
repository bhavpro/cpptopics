#include <iostream>

using namespace std;

int main()
{
    int arr[] = {4, 1, 2, -1, 1, -3};
    int n = sizeof(arr) / sizeof(int);
    int t = 1;

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int target = t - arr[i] - arr[j];
            int k = j + 1;
            int m = n - 1;
            while (k < m)
            {
                if (arr[k] + arr[m] == target)
                {
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[m] << "\n";
                    k++;
                    continue;
                }
                if (arr[k] + arr[m] < target)
                {
                    k++;
                    continue;
                }
                m--;
            }
        }
    }
    return 0;
}