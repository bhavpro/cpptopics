#include <iostream>
#include <vector>

using namespace std;

vector<long long> calcprime(long long a)
{
    vector<long long> v;
    for (int i = 2; i * i <= a || a != 1; i++)
    {
        if (a % i == 0)
        {
            v.push_back(i);
            while (a % i == 0)
            {
                a /= i;
            }
        }
    }
    if (a != 1)
    {
        v.push_back(a);
    }
    return v;
}

long long dototient(long long a, vector<long long> p)
{
    long long x = a;
    for (int i = 0; i < p.size(); i++)
    {
        x = x * (1 - (double)1 / p[i]);
    }
    return x;
}

long long totient(long long a)
{
    return dototient(a, calcprime(a));
}

long long gcd(long long a, long long b)
{
    if (a < b)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    long long a;
    cin >> a;
    long long b;
    cin >> b;
    cout << "\nphi(a) -> " << totient(a);
    cout << "\nphi(b) -> " << totient(b);
    cout << "\nphi(a * b) -=> " << totient(a * b);
    cout << "\nphi(a) * phi(b) * gcd / phi(gcd)==> " << totient(a) * totient(b) / totient(gcd(a, b)) * gcd(a, b);
    return 0;
}