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

int longsub(int a[], int n, int k)
{
    unordered_map<int, int> ind;
    int pre = 0;
    int maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        pre += a[i];
        if (a[i] == k)
        {
            maxlen = max(1, maxlen);
        }
        if (pre == k)
        {
            maxlen = max(maxlen, i + 1);
        }
        if (ind.count(pre - k) == 0)
        {
            ind[pre] = i;
            continue;
        }
        if (i - ind[pre - k] > maxlen)
        {
            maxlen = i - ind[pre];
            continue;
        }
    }
    return maxlen;
}

int main()
{
    int a[] = {6, -1, 0, 2, -3};
    int n = 5;
    int k = 4;
    cout << longsub(a, n, k);
    return 0;
}