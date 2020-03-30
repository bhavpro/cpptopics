#include <iostream>
#include <math.h>

using namespace std;

int fastmodulo(int a, int b, int m)
{
    int mul = a % m;
    int res = 1;
    while (b > 0)
    {
        if ((b & 1) == 1)
        {
            res = (res * mul) % m;
        }
        mul = (mul * mul) % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    cout << ((int)pow(a, b)) % m;
    cout << fastmodulo(a, b, m);
    return 0;
}