#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ed = n % 7;
    int w = n / 7;
    long long comp = (w << 1);
    int mi = 0, ma = 0;
    if (ed >= 5)
        mi = ed % 5;
    if (ed == 1)
        ma = 1;
    if (ed >= 2)
        ma = 2;
    cout << comp + mi << " " << comp + ma;
    return 0;
}