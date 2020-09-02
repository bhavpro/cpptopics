#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int timerem = 60 * 4 - k;
    for (int i = 1; i <= n; i++)
    {
        sum += 5 * i;
        if (sum == timerem)
        {
            cout << i;
            break;
        }
        if (sum > timerem)
        {
            cout << i - 1;
            break;
        }
        if(i == n)
        {
            cout << n;
            break;
        }
    }
    return 0;
}