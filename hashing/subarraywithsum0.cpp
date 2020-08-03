#include <bits/stdc++.h>

using namespace std;

bool count(int a[], int n)
{
    map<int, int> count;
    int presum = 0;
    for (int i = 0; i < n; i++)
    {
        presum += a[i];
        if (count.count(presum) == 0)
        {
            count[presum] = 1;
            continue;
        }
    }
    return false;
}

int main()
{
    int a[] = {6, -1, 2, 1, -1};
    int n = 5;
    cout << count(a, n);
    return 0;
}