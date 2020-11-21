#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<bool> a(2);
    a[0] = 0;
    a[1] = 1;
    sort(a.begin(), a.end());
    cout << a[0] << a[1];
}