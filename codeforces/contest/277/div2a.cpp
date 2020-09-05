#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ll a;
    cin >> a;
    if (a & 1)
        cout << (a >> 1) - a;
    else
        cout << (a >> 1);
    return 0;
}