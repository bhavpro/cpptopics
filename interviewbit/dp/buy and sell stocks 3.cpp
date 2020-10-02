#include <bits/stdc++.h>

using namespace std;

#define ll long long

int maxProfit(const vector<int> &A)
{
    int n = A.size();
    if (n == 0)
        return 0;
    vector<int> b(n), s(n);

    s[0] = 0;
    int minele = A[0];
    for (int i = 1; i < n; i++)
    {
        s[i] = max(A[i] - minele, s[i - 1]);
        minele = min(minele, A[i]);
    }

    b[n - 1] = 0;
    int maxsel = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        b[i] = max(maxsel - A[i], b[i + 1]);
        maxsel = max(maxsel, A[i]);
    }

    int maxp = max(b[0], s[n - 1]);
    for (int i = 1; i < n - 1; i++)
    {
        int temp = max(s[i] + b[i + 1], b[i] + s[i - 1]);
        maxp = max(maxp, temp);
    }

    return maxp;
}
