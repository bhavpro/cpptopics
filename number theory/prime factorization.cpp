#include <iostream>
#include <vector>

using namespace std;

vector<int> primesieve(int n)
{
    vector<bool> arr(n + 1, true);
    arr[1] = arr[0] = false;
    arr[2] = true;
    for (int i = 4; i <= n; i += 2)
    {
        arr[i] = false;
    }

    for (int i = 3; i <= n; i += 2)
    {
        if (arr[i] == true)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                arr[j] = false;
            }
        }
    }

    // we got a bool array having primes
    // we will convert it to an array of primes

    vector<int> primes;
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] == true)
            primes.push_back(i);
    }
    return primes;
}

vector<int> primefactors(vector<int> &primes, int n)
{
    vector<int> factors;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++)
    {
        int div = primes[i];
        if (n % div == 0)
        {
            factors.push_back(div);
            while (n % div == 0)
            {
                n /= div;
            }
        }
    }

    if (n != 1)
    {
        factors.push_back(n);
    }
    return factors;
}

int main()
{
    int n;
    cin >> n;
    vector<int> temp = primesieve(n);
    vector<int> pf = primefactors(temp, n);
    for (int i = 0; i < pf.size(); i++)
    {
        cout << pf[i] << " ";
    }
    return 0;
}