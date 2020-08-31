#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

int N = 1e6;
int bs(int a[], int n, int num)
{
    int count = 0, ans = -1;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        count++;
        int mid = s + e;
        mid >>= 1;
        if (a[mid] == num)
        {
            ans = mid;
            break;
        }
        if (num < a[mid])
        {
            e = mid - 1;
            continue;
        }
        s = mid + 1;
    }
    cout << count << "\n";
    return ans;
}

int ts(int a[], int n, int num)
{
    int count = 0;
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        count++;
        int temp = e - s;
        int mid1 = s + temp / 3;
        int mid2 = s + (2 * (temp)) / 3;
        if (a[mid1] == num)
        {
            ans = mid1;
            break;
        }
        if (a[mid2] == num)
        {
            ans = mid2;
            break;
        }
        if (num < a[mid1])
        {
            e = mid1 - 1;
            continue;
        }
        if (num > a[mid2])
        {
            s = mid2 + 1;
            continue;
        }
        s = mid1 + 1;
        e = mid2 - 1;
    }
    cout << count << "\n";
    return ans;
}

int qs(int a[], int n, int num)
{
    int count = 0;
    int s = 0;
    int e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        count++;
        int temp = e - s;
        int mid1 = s + temp / 4;
        int mid2 = s + (2 * temp) / 4;
        int mid3 = s + (3 * temp) / 4;
        if (a[mid1] == num)
        {
            ans = mid1;
            break;
        }
        if (a[mid2] == num)
        {
            ans = mid2;
            break;
        }
        if (a[mid3] == num)
        {
            ans = mid3;
            break;
        }
        if (num < a[mid1])
        {
            e = mid1 - 1;
            continue;
        }
        if (num > a[mid3])
        {
            s = mid2 + 1;
            continue;
        }
        if (num > a[mid1] && num < a[mid2])
        {
            s = mid1 + 1;
            e = mid2 - 1;
            continue;
        }
        s = mid2 + 1;
        e = mid3 - 1;
    }
    cout << count << "\n";
    return ans;
}

int main()
{
    int a[N];
    int n = N;
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
    }
    int s = 9039;
    bs(a, n, s);
    ts(a, n, s);
    qs(a, n, s);

    return 0;
}