#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <bitset>

using namespace std;

vector<pair<int, int>> naive(int n)
{
    vector<pair<int, int>> ans;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            pair<int, int> p;
            p.first = i;
            p.second = 0;
            while (n % i == 0)
            {
                n = n / i;
                p.second++;
            }
            ans.push_back(p);
        }
    }
    return ans;
}

vector<pair<int, int>> optimized(int n)
{
    vector<pair<int, int>> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            pair<int, int> p;
            p.first = i;
            p.second = 0;
            while (n % i == 0)
            {
                n = n / i;
                p.second++;
            }
            ans.push_back(p);
        }
    }
    if (n != 1)
    {
        ans.push_back(make_pair(n, 1));
    }
    return ans;
}

void bitsetsieve(vector<int> &primes)
{
    int n = 10000000;
    bitset<10000005> bita;
    bita.set();
    bita[0] = bita[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (bita[i] == 1)
        {
            primes.push_back(i);
            for (long long j = i * (long long)i; j <= n; j += i)
            {
                bita[j] = 0;
            }
        }
    }
}

vector<pair<int, int>> sieveprimes(int n, vector<int> primes)
{
    vector<pair<int, int>> ans;
    int i = 0;
    while (primes[i] * primes[i] <= n)
    {
        if (n % primes[i] == 0)
        {
            pair<int, int> p;
            p.first = primes[i];
            p.second = 0;
            while (n % primes[i] == 0)
            {
                n = n / primes[i];
                p.second++;
            }
            ans.push_back(p);
        }
        // last
        i++;
    }
    if (n != 1)
    {
        ans.push_back(make_pair(n, 1));
    }
    return ans;
}

void output(vector<pair<int, int>> v)
{
    cout << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].second; j++)
        {
            cout << v[i].first << ", ";
        }
    }
    cout << flush;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> p1 = naive(n);
    output(p1);
    vector<pair<int, int>> p2 = optimized(n);
    output(p2);
    vector<int> primes;
    bitsetsieve(primes);
    vector<pair<int, int>> p3 = sieveprimes(n, primes);
    output(p3);
    return 0;
}