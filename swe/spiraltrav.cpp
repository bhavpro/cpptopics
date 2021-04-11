#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int arr[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    int n = 5;

    vector<int> v(n * n, 0);

    int r1 = 0, r2 = n - 1, c1 = 0, c2 = n - 1;

    while (r1 <= r2 && c1 <= c2)
    {
        for (int i = c1; i <= c2; i++)
            cout << arr[r1][i] << " ";
        r1++;
        for (int i = r1; i <= r2; i++)
            cout << arr[i][c2] << " ";
        c2--;
        for (int i = c2; i >= c1; i--)
            cout << arr[r2][i] << " ";
        r2--;
        for (int i = r2; i >= r1; i--)
            cout << arr[i][c1] << " ";
        c1++;
    }

    return 0;
}