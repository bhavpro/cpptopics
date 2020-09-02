#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int count = 0;
    int cmax = 0;
    char x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        count = x == '#' ? count + 1 : 0;
        cmax = max(cmax, count);
    }
    cout << (cmax < k ? "YES" : "NO");
    return 0;
}