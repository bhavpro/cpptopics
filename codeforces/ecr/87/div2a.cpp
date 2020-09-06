#include <bits/stdc++.h>

using namespace std;

long long solve(int a, int b, int c, int d)
{
    if (b >= a)
        return b;
    if (c <= d)
        return -1;
    long long totaltime = b;
    long long count = b;
    long long add = c - d;
    long long cycles = ceil(double(a - b) / (c - d));
    totaltime += c * cycles;
    return totaltime;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve(a, b, c, d) << "\n";
    }
    return 0;
}