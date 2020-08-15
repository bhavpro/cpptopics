#include <bits/stdc++.h>

using namespace std;

int maxd(int temp)
{
    int maxi = 0;
    while (temp != 0)
    {
        maxi = max(temp % 10, maxi);
        temp = temp / 10;
    }
    return maxi;
}

int solve(int n)
{
    int ways = 0;
    while (n != 0)
    {
        ways++;
        n = n - maxd(n);
    }
    return ways;
}

int main()
{
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}