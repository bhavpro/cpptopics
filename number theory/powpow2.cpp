#include <iostream>

using namespace std;

int mod = 1000000007;

int powmod(int a, int p, int mod)
{
    // base
    if (p <= 1)
    {
        if (p == 1)
        {
            return a;
        }
        else
        {
            return 1;
        }
    }

    // rec
    long long temp = powmod(a, p / 2, mod);
    temp = (temp * temp) % mod;
    if (p & 1 == 1) // odd power
    {
        temp = (a * temp) % mod;
    }
    return temp;
}

int inversefactmodprime(int x, int mod)
{
    if (mod == 2)
    {
        return 1;
    }

    // calculate factorial mod

    long long ans = 1;
    while (x != 1)
    {
        ans = (ans * x) % mod;
        x--;
    }

    // calculate power mod

    int power = mod - 2;
    ans = powmod(ans, power, mod);
    return ans;
}

int calcinverse(int n, int mod)
{
    long long i = 1;
    if (n % mod == 0)
    {
        return 0;
    }

    while ((n * i) % mod != 1)
    {
        if (i == mod)
        {
            cerr << "calc inverse error :: " << i << " i == mod " << mod;
            return -1;
        }
        i++;
    }
    return i % mod;
}

int inversefactmodcomposite(int x, int mod)
{
    long long ans = 1;
    for (int i = 2; i <= x; i++)
    {
        ans = (ans * calcinverse(i, mod)) % mod;
    }
    return ans;
}

int powpow2(int a, int b, int n)
{
    int ans = 1;

    return ans;
}

int main()
{
    int a, b, n;
    cout << "\na : ";
    cin >> a;
    cout << "\nb : ";
    cin >> b;
    cout << "\nn : ";
    cin >> n;
    cout << powpow2(a, b, n);
    return 0;
}