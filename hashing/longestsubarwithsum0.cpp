#include <bits/stdc++.h>

using namespace std;

int longestsubsum0(int a[], int n)
{
    unordered_map<int, int> fi;
    int maxl = 0;
    int presum = 0;
    for (int i = 0; i < n; i++)
    {
        presum += a[i];
        if (a[i] == 0)
        {
            maxl = max(1, maxl);
        }
        if (presum == 0)
        {
            maxl = max(maxl, i + 1);
        }
        if (fi.find(presum) == fi.end())
        {
            fi[presum] = i;
        }
        else
        {
            maxl = max(maxl, i - fi[presum]);
        }
    }
    return maxl;
}

int main()
{
    int a[] = {6, -1, 0, 2, -1};
    int n = 5;
    cout << longestsubsum0(a, n);
    return 0;
}