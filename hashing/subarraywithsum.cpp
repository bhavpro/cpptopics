#include <bits/stdc++.h>

using namespace std;

bool sub(int a[], int n, int k)
{
    map<int, bool> hash;
    int cur = a[0];
    hash[cur] = true;
    for (int i = 1; i < n; i++)
    {
        cur += a[i];
        if (hash[cur - k] == true)
        {
            return true;
        }
        hash[cur] = true;
    }
    return false;
}

int main()
{
    int a[] = {6, -1, 2, 1, -1};
    int n = 5;
    int k = -1;
    cout << (sub(a, n, k) == 1 ? "YES" : "NO");
    return 0;
}