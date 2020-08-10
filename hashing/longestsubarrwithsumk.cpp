#include <bits/stdc++.h>

using namespace std;

int longestsubsumk(int *arr, int n, int k)
{
    int pre = 0;
    int maxl = 0;
    unordered_map<int, int> fi;
    for (int i = 0; i < n; i++)
    {
        pre += arr[i];
        if (arr[i] == k)
            maxl = max(maxl, 1);

        if (pre == k)
            maxl = max(maxl, i + 1);

        if (fi.count(pre) == 0)
        {
            fi[pre] = i;
        }
        if (fi.count(pre - k) != 0)
        {
            maxl = max(maxl, i - fi[pre - k]);
        }
    }
    return maxl;
}

int main()
{
    int a[] = {6, -1, 0, 2, -1};
    int n = 5;
    cout << longestsubsumk(a, n, 0);
    return 0;
}