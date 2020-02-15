#include <iostream>
#include <math.h>

using namespace std;

bool isprime(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i <= pow(n, 0.5); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << isprime(n);
    return 0;
}