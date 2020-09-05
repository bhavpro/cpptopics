#include <bits/stdc++.h>

using namespace std;

vector<int> sieve(int A)
{
    vector<int> primes;
    bitset<100001> b;
    b.set();
    for (int i = 2; i <= A; i++)
    {
        if (b[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= A; j += i)
            {
                b[j] = 0;
            }
        }
    }
    return primes;
}
