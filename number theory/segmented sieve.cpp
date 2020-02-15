#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void sieve(vector<int> &arr, int a, int b)
{
    int sqrtb = pow(b, 0.5);
    vector<int> sieve(sqrtb + 1, 1);
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i <= sqrtb; i++)
    {
        if (sieve[i] == 1)
        {
            for (int j = 2 * i; j <= sqrtb; j += i)
            {
                sieve[j] = 0;
            }
        }
    }
    // we have got a prime sieve from 2 to sqrt(b)
    for (int i = 2; i < sieve.size(); i++)
    {
        if (sieve[i] == 0)
        {
            continue;
        }
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] == 1)
            {
                if ((a + j) % i == 0)
                {
                    arr[j] = 0;
                }
            }
        }
    }
}

int main()
{
    long long a, b;
    cin >> a >> b;
    vector<int> arr(b - a + 1, 1);
    sieve(arr, a, b);
    long long q;
    cin >> q;
    cout << "\n" <<arr[q - a];
    return 0;
}