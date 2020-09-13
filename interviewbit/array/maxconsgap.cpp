#include <bits/stdc++.h>

using namespace std;

int pegionholesort(vector<int> &a)
{
    int minel, maxel;
    minel = maxel = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        minel = min(minel, a[i]);
        maxel = max(maxel, a[i]);
    }

    int range = maxel - minel + 1;
    vector<int> temp(range, 0);

    for (int x : a)
        temp[x - minel]++;

    for (int i = 0; i < temp.size(); i++)
    {
        while (temp[i] > 0)
        {
            temp[i]--;
            a.push_back(minel + i);
        }
    }
}

int maximumGap(const vector<int> &A)
{
    vector<int> a(A);
    return pegionholesort(a);
}
