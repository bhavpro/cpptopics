#include <iostream>

using namespace std;

int n = 50;

void makesieve(bool arr[])
{
    arr[1] = arr[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            for (int j = 2; i * j <= n; j++)
            {
                arr[i * j] = 0;
            }
        }
    }
}

void optimisedsieve(bool arr[])
{
    arr[1] = arr[0] = 0;
    arr[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        if (i % 2 == 0) // even
        {
            arr[i] = 0;
        }

        if (arr[i] == 1)
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = 0;
            }
        }
    }
}

int main()
{
    bool sieve[51];
    for (int i = 0; i <= n; i++)
    {
        sieve[i] = 1;
    }
    int q;
    cin >> q;
    optimisedsieve(sieve);
    cout << (sieve[q] == 1 ? "Prime" : "Not Prime");
    return 0;
}