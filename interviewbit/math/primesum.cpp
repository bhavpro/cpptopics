#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 1;

vector<int> primesum(int A)
{
    bitset<N> isprime;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for (int i = 4; i <= A; i += 2)
    {
        isprime[i] = 0;
    }
    for (int i = 3; i <= A; i += 2)
    {
        if (isprime[i])
        {
            for (long long j = (long long)i * i; j <= A; j += 2 * i)
            {
                isprime[j] = 0;
            }
        }
    }

    vector<int> ans;
    for (int i = 2; i <= A; i++)
    {
        if (isprime[i])
        {
            if (isprime[A - i])
            {
                ans.push_back(i);
                ans.push_back(A - i);
                break;
            }
        }
    }
    return ans;
}

int main()
{
}