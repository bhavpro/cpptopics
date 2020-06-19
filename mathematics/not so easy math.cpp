#include <iostream>

using namespace std;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19};

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % p[j] == 0)
            {
                cout << i << " , ";
                break;
            }
        }
    }
}