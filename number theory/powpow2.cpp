#include <iostream>

using namespace std;

const int mod = 1000000007;

int arr[mod][mod];

int rec2ncn(int n, int r, int mod)
{
    // base
    if (r == 1)
    {
        return n;
    }

    if (r == 0 or n == r)
    {
        return 1;
    }

    // rec
    int a = rec2ncn(n - 1, r, mod);
    int b = rec2ncn(n - 1, r - 1, mod);
    return ((long long)a + (long long)b) % mod;
}

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

int factmod(int h, int l, int mod)
{
    long long ans = 1;
    for (int i = h; i >= l; i--)
    {
        ans = (ans * (i % mod)) % mod;
    }
    return ans;
}

int _2nCn(int n, int mod)
{
    long long num = factmod(2 * n, n + 1, mod);
    int denominv;
    if (mod == 1681)
    {
        denominv = inversefactmodcomposite(n, mod);
    }
    else
    {
        denominv = inversefactmodprime(n, mod);
    }
    num = num * denominv;
    num %= mod;
    return num;
}

int chineserem3(int m1, int r1, int m2, int r2, int m3, int r3)
{
    int prod = m1 * m2 * m3;
    long long sum = 0;
    int pp1, pp2, pp3;
    int inv1, inv2, inv3;
    pp1 = prod / m1;
    pp2 = prod / m2;
    pp3 = prod / m3;
    inv1 = 1;
    inv2 = calcinverse(pp2, m2);
    inv3 = powmod(pp3, m3 - 2, m3);
    sum += (r1 * pp1 * inv1) % prod;
    sum %= prod;
    sum += (r2 * pp2 * inv2) % prod;
    sum %= prod;
    sum += (r3 * pp3 * inv3) % prod;
    sum %= prod;
    return sum;
}

int chineserem2(int m1, int r1, int m2, int r2)
{
    int prod = m1 * m2;
    int pp1, pp2;
    int inv1, inv2;
    pp1 = prod / m1;
    pp2 = prod / m2;
    inv1 = 1;
    inv2 = powmod(pp2, m2 - 2, m2);
    long long sum = 0;
    sum += (r1 * pp1 * inv1) % prod;
    sum %= prod;
    sum += (r2 * pp2 * inv2) % prod;
    sum %= prod;
    return sum;
}

int powpow2(int a, int b, int n)
{
    int r1 = rec2ncn(2 * n, n, 2);
    int r3 = rec2ncn(2 * n, n, 148721);
    int r2 = rec2ncn(2 * n, n, 1681);
    int exp = chineserem3(2, r1, 1681, r2, 148721, r3);
    int r4 = powmod(b, exp, 2);
    int r5 = powmod(b, exp, 500000003);
    int bexp = chineserem2(2, r4, 500000003, r5);
    return powmod(a, bexp, ::mod);
}

int main()
{

    int a, b, n, t;
    cin >> t;
    for (int i = 0; i < mod; i++)
    {
        arr[mod][0] = 1;
    }
    for(int i =0;)
    while (t--)
    {
        cin >> a >> b >> n;
        cout << powpow2(a, b, n);
    }

    return 0;
}