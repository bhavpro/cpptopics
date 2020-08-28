#include <bits/stdc++.h>

using namespace std;

#define itr(s, e) for (int i = s; i <= e; i++)

bool gettri(int *a, int n)
{
    itr(1, n)
    {
        if (a[a[a[i]]] == i)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);
    int n, *a;
    cin >> n;
    a = new int[n + 1];
    itr(1, n)
    {
        cin >> a[i];
    }
    cout << (gettri(a, n) == true ? "YES" : "NO");
    delete[] a;
    return 0;
}