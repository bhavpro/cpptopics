#include <iostream>

using namespace std;

long long primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

int main()
{
    long long n;
    cin >> n;
    long long sum = 0;
    long long no = (1 << 8) - 1;
    for (long long i = 1; i <= no; i++)
    {
        long long denom = 1;
        for (long long j = 0; j <= 7; j++)
        {
            if (i & (1 << j))
            {
                denom = denom * primes[j];
            }
        }
        int sets = __builtin_popcount(i);
        if (sets & 1)
        {
            sum += (long long)(n / denom);
        }
        else
        {
            sum -= (long long)(n / denom);
        }
    }
    cout << sum;
    return 0;
}