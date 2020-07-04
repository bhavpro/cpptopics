#include <iostream>

using namespace std;

long long power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }

    int i = a;
    int ans = 1;
    while (b != 0)
    {
        if (b & 1 == 1)
        {
            ans *= i;
        }
        b >>= 1;
        i *= i;
    }

    return ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << power(a, b);
    return 0;
}