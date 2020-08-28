#include <bits/stdc++.h>

using namespace std;

#define input(a, n)              \
    for (int i = 1; i <= n; i++) \
        cin >> a[i];

#define FIO                          \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(0);                      \
    cout.tie(0)

const int N = 1005;

int rec(int *a, bitset<N> &badge, int i)
{
    // base
    if (badge[i])
    {
        return i;
    }

    // rec
    badge[i] = 1;
    return rec(a, badge, a[i]);
}

int *solve(int *a, int n)
{
    int *ans = new int[n + 1];
    bitset<N> badge;
    for (int start = 1; start <= n; start++)
    {
        badge.reset();
        ans[start] = rec(a, badge, start);
    }
    return ans;
}

int *iter(int *a, int n)
{
    int *ans = new int[n + 1];
    bitset<N> badge;
    for (int i = 1; i <= n; i++)
    {
        badge.reset();
        int j = i;
        while (badge[j] == 0)
        {
            badge[j] = 1;
            j = a[j];
        }
        ans[i] = j;
    }
    return ans;
}

int main()
{
    FIO;
    int n;
    cin >> n;
    int *a;
    a = new int[n + 1];
    input(a, n);
    int *ans = iter(a, n);
    //
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    //
    delete[] a;
    delete[] ans;
    return 0;
}