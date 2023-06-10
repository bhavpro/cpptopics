#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int mid = n >> 1;
    mid --;

    for (int i = 0; i < n; i++)
    {
        cout << "\n";
        if (i <= mid)
        {
            for (int j = 0; j < i; j++)
                cout << " ";
            for (int j = 0; j <= i; j++)
                cout << "* ";
        }
        else
        {
            int ni = (mid << 1) - i;
            for (int j = 0; j < ni; j++)
                cout << " ";
            for (int j = 0; j <= ni; j++)
                cout << "* ";
        }
    }
    cout << "\n";
    return 0;
}