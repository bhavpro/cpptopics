#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int gcdoptimized(int a, int b)
{
    return b == 0 ? a : (a % b == 0 ? b : gcd(a % b, b % (a % b)));
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "HCF is " << gcdoptimized(max(a, b), min(a, b));
    cout << "\nLCM is " << a * b / gcd(a, b);
    return 0;
}