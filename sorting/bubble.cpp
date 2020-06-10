#include <iostream>

using namespace std;

int a[] = {67, 37, 86, 24, 87, 45, 62, 94, 32, 12};
int n = sizeof(a) / sizeof(int);

int main()
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}