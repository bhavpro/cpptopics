#include <iostream>

using namespace std;

const int n = 999999;

void optimisedsieve(bool arr[1000000])
{
    arr[1] = arr[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 1)
        {
            if (i % 2 == 0 && i != 2) // even
            {
                arr[i] = 0;
            }

            for (int j = i * i; j <= n && j >= 0; j += i)
            {
                arr[j] = 0;
            }
        }
    }
}

int main()
{
    bool sieve[1000000];
    int cs[1000000];
    int t;
    cin >> t;
    for (int i = 0; i <= n; i++)
    {
        sieve[i] = 1;
    }
    optimisedsieve(sieve);
    cs[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cs[i] = cs[i - 1] + sieve[i];
    }
    while (t > 0)
    {
        int a, b;
        cin >> a >> b;
        cout << cs[b] - cs[a - 1];
        t--;
    }
    return 0;
}