#include <bits/stdc++.h>

using namespace std;

#define ll long long

pair<int, int> solve(int *a, int n)
{
    ll sumser = (n - 2) * (n - 1) / 2;
    ll sumarr = 0;
    ll prodarr = 1;
    int prodser = 1;
    for (int i = 0; i < n; i++)
    {
        sumarr += a[i];
        prodarr *= a[i];
        if (i != 0 && i != n - 1)
        {
            prodser *= i;
        }
    }
    ll sumnum = sumarr - sumser;
    ll prodnum = prodarr / prodser;
    ll diffnum = sqrt(sumnum * sumnum - 4 * prodnum);
    return {(sumnum + diffnum) >> 1, (sumnum - diffnum) >> 1};
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    pair<int, int> p = solve(a, n);
    cout << p.first << " " << p.second;
    delete[] a;
    return 0;
}