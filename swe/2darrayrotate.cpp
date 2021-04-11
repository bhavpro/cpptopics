#include <iostream>
#include <vector>

using namespace std;

void inplace(int arr[][4], int n)
{
    int r1 = 0;
    int r2 = n - 1;
    int c1 = 0;
    int c2 = n - 1;
    for (int i = n; i >= 2; i -= 2)
    {
        for (int j = 0; j < i - 1; j++)
        {
            int temp = arr[r1][c1 + j];
            arr[r1][c1 + j] = arr[r2 - j][c1];
            arr[r2 - j][c1] = arr[r2][c2 - j];
            arr[r2][c2 - j] = arr[r1 + j][c2];
            arr[r1 + j][c2] = temp;
        }
        r1++;
        r2--;
        c1++;
        c2--;
    }
}

int main()
{
    int arr[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int n = 4;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << "\t";
        cout << "\n";
    }

    inplace(arr, n);

    cout << "\n\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << "\t";
        cout << "\n";
    }

    return 0;
}