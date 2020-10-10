#include <bits/stdc++.h>

using namespace std;

int maxp(vector<int> &p, int l, int r)
{
    // base
    // rec
    int maxprice = 0;
    for (int i = l + 1; i < r; i++)
    {
        if (p[i] == -1)
            continue;
        int temp = p[i];
        int li = i - 1, ri = i + 1;
        while (li > l && p[li] == -1)
            li--;
        while (ri < r && p[ri] == -1)
            ri++;
        int price = p[li] * p[ri] * p[i];
        p[i] = -1;
        maxprice = max(maxprice, price + maxp(p, l, r));
        p[i] = temp;
    }
    return maxprice;
}

int maxp1(vector<int> p, int l, int r)
{
    if (r - l <= 1)
        return 0;

    int a = 0;
    for (int i = l + 1; i < r; i++)
    {
        a = max(a, p[l] * p[r] * p[i] + maxp1(p, l, i) + maxp1(p, i, r));
    }
    return a;
}

int maxp2(vector<int> &p, int l, int r)
{
    // base
    if (l + 1 == r)
        return 0;

    // rec
    int maxa = 0;
    for (int i = l + 1; i < r; i++)
    {
        int price = p[l] * p[r] * p[i];
        maxa = max(maxa, price + maxp2(p, l, i) + maxp2(p, i, r));
    }
    return maxa;
}

int main()
{
    int n;
    cin >> n;
    vector<int> p(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    p[0] = 1;
    p[n + 1] = 1;
    cout << maxp2(p, 0, n + 1);
    return 0;
}