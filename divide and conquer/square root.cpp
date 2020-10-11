#include <bits/stdc++.h>

using namespace std;

double mysqrt(int n, int p)
{
    int s = 0;
    int e = n;
    double ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        long long sqred = mid * mid;
        if (sqred == n)
        {
            return mid;
        }
        if (sqred > n)
        {
            e = mid - 1;
            continue;
        }
        ans = mid;
        s = mid + 1;
    }

    // decimal part
    float inc = 0.1;
    for (int times = 0; times < p; times++)
    {
        while (ans * ans <= n)
        {
            ans += inc;
        }
        ans -= inc;
        inc /= 10;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << mysqrt(n, 3);
    return 0;
}