#include <bits/stdc++.h>

using namespace std;

bool sortit(int a, int b)
{
    return a > b;
}

int getMinimumCost(int k, vector<int> c)
{
    sort(c.begin(), c.end(), sortit);
    int noofc = 1;
    int sum = 0;
    for (int i = 0; i < c.size() - (k - 1); i++)
    {
        sum += c[i];
    }
    for (int i = 1; i < k; i++)
    {
        sum += (noofc + 1) * c[i + k - 1];
        noofc++;
    }
    return sum;
}

int main()
{
    return 0;
}