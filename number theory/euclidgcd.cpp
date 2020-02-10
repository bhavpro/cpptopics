#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << "HCF is " << gcd(max(a, b), min(a, b));
    cout << "\nLCM is " << a * b / gcd(a, b);
    return 0;
}