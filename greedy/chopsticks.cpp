#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    long long d;
    cin >> n >> d;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] <= d)
        {
            count++;
            i++;
        }
    }
    cout << count;
    return 0;
}