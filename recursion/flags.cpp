#include <iostream>
using namespace std;

int nof(int n, int prev = 0, int prev1 = -1)
{
    // base
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // rec
    if (prev == 0)
        return nof(n - 1, 1, 0) + nof(n - 1, 3, 0);

    if (prev == 1)
        return nof(n - 1, 2, 1) + nof(n - 1, 3, 1);
    else if (prev == 3)
        return nof(n - 1, 1, 3) + nof(n - 1, 2, 3);
    else if (prev == 2)
    {
        if (prev1 == 1)
            return nof(n - 1, 3, 2);
        else
            return nof(n - 1, 1, 2);
    }
    else
        return -1;
}

int main()
{
    int n;
    cin >> n;
    cout << nof(n, 0);
    return 0;
}