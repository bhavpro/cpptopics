#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    cout << (((n & 1) || n == 0 || n == 2) ? "NO" : "YES") << "\n";
    return 0;
}
