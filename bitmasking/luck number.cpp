#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // find no of digits
    int d = 0;
    int temp = n;
    int i = 0;
    bitset<32> b;
    b.reset();
    while (temp != 0)
    {
        if (temp % 10 == 7)
        {
            b[i] = 1;
        }
        i++;
        temp /= 10;
        d++;
    }
    int totalndigits = b.to_ulong() + 1;

    // calc less than n digiters
    int sum = 0;
    for (i = 1; i <= d - 1; i++)
    {
        sum += (1 << i);
    }
    cout << sum + totalndigits;
    return 0;
}