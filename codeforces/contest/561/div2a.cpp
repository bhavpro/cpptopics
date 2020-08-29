#include <bits/stdc++.h>

using namespace std;

int comb2(int n, int r)
{
    // base
    if (r == 0 || r == n)
        return 1;
    if (r == 1 || r == n - 1)
        return n;

    // rec
    return comb2(n - 1, r - 1) + comb2(n - 1, r);
}

int comb(int n, int r)
{
    long long count = 1;
    for (int i = n; i > n - r; i--)
    {
        count *= i;
    }
    for (int i = 1; i <= r; i++)
    {
        count = count / i;
    }
    return count;
}

long long nocp(unordered_map<char, int> &fc, unordered_map<char, int> &sc, int n)
{
    long long count = 0;
    for (pair<char, int> p : fc)
    {
        if (p.second > 1)
            count += comb2(p.second, 2);
    }
    for (pair<char, int> p : sc)
    {
        if (p.second > 1)
            count += comb2(p.second, 2);
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    unordered_map<char, int> fc, sc;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        char x = s[0];
        if (fc[x] <= sc[x])
            fc[x]++;
        else
            sc[x]++;
    }
    cout << nocp(fc, sc, n);
    return 0;
}