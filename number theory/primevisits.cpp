#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

int n = 10000000;
bitset<10000004> bitarr;

void bitsetsieve(vector<int> &arr)
{
    bitarr.set();
    bitarr[0] = bitarr[1] = 0;
    arr.push_back(0);
    arr.push_back(0);
    for (int i = 2; i <= n; i++)
    {
        if (bitarr[i] == 1)
        {
            arr.push_back(*(arr.end() - 1) + 1);
            for (long long j = (long long)i * i; j <= n; j += i)
            {
                bitarr[j] = 0;
            }
        }
        else
        {
            arr.push_back(*(arr.end() - 1));
        }
    }
}

int main()
{
    int t, a, b;
    vector<int> csum;
    bitsetsieve(csum);
    cin >> t;
    while (t > 0)
    {
        cin >> a >> b;
        cout << csum[b] - csum[a - 1];
        t--;
    }
    return 0;
}