#include <iostream>

using namespace std;

typedef long long ll;

int p[] = {2, 3, 5, 7, 11, 13, 17, 19};

int main()
{
    int n;
    cin >> n;
    ll s = (1 << 8) - 1;
    int sum = 0;
    for (int pp = 1; pp <= s; pp++)
    {
        ll denom = 1;
        int noof1 = __builtin_popcount(pp);
        for (int i = 0; i < 8; i++)
        {
            if ((pp & 1) == 1)
            {
                denom = denom * p[i];
            }
        }
        int temp = (ll)n/denom;
        sum += noof1 & 1 == 1 ? temp : -temp;
    }
    cout << sum;
    return 0;
}