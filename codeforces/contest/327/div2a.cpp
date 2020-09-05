#include <bits/stdc++.h>

using namespace std;

double solve(int l, int s1, int s2)
{
    double a = l / (1 + (double(s2) / s1));
    return a;
}

int main()
{
    int l, s1, s2;
    cin >> l;
    cin >> s1;
    cin >> s2;
    cout << solve(l, s1, s2);
    return 0;
}